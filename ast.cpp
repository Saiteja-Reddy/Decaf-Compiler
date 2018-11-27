#include "ast.h"
using namespace std;

bool Statements::has_return() {
    for (int i = 0; i < statements_list.size(); i++) {
        if (statements_list[i]->has_return()) {
            return true;
        }
    }
    return false;
}

bool ifElseState::has_return() {
    bool status = false;
    if (if_block != nullptr) {
        status = status | if_block->has_return();
    }
    if (else_block != nullptr) {
        status = status | if_block->has_return();
    }
    return status;
}


bool Block::has_return() {
    return statements_list->has_return();
}


bool Statements::has_break() {
    for (int i = 0; i < statements_list.size(); i++) {
        if (statements_list[i]->has_break()) {
            return true;
        }
    }
    return false;
}

bool ifElseState::has_break() {
    bool status = false;
    if (if_block != nullptr) {
        status = status | if_block->has_break();
    }
    if (else_block != nullptr) {
        status = status | if_block->has_break();
    }
    return status;
}


bool Block::has_break() {
    return statements_list->has_break();
}

bool Statements::has_continue() {
    for (int i = 0; i < statements_list.size(); i++) {
        if (statements_list[i]->has_continue()) {
            return true;
        }
    }
    return false;
}

bool ifElseState::has_continue() {
    bool status = false;
    if (if_block != nullptr) {
        status = status | if_block->has_continue();
    }
    if (else_block != nullptr) {
        status = status | if_block->has_continue();
    }
    return status;
}


bool Block::has_continue() {
    return statements_list->has_continue();
}

Value *generateError(string error_str) {
    cerr << error_str << endl;
    return nullptr;
}

string replace_newline(string str) {
    size_t index = 0;
    string search = "\\n";
    while (true) {
        index = str.find(search, index);
        if (index == std::string::npos) break;
        str.erase(index, search.length());
        str.insert(index, "\n");
        index += 1;
    }
    return str;
}

AllocaInst *CreateEntryBlockAlloca(Function *TheFunction, string VarName, string type) {
    IRBuilder<> TmpB(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
    AllocaInst *alloca_instruction = nullptr;
    if (type == "int") {
        alloca_instruction = TmpB.CreateAlloca(Type::getInt32Ty(Context), 0, VarName);
    } else if (type == "boolean") {
        alloca_instruction = TmpB.CreateAlloca(Type::getInt1Ty(Context), 0, VarName);
    }
    return alloca_instruction;
}

void ProgramASTnode::generateCodeDump()
{
    cerr << "Generating LLVM IR Code\n\n";
    std::string Str;
    raw_string_ostream OS(Str);
    OS << *TheModule;
    OS.flush();
    ofstream out("output.txt");
    out << Str;
    out.close();
    system("sh decaf_linker.sh");
}

Value* ASTnode::Codegen()
{
    return nullptr;
}

Value* ProgramASTnode::Codegen()
{
    Value *V;
    cout << "\n\n\nNow generating code\n";
    V = fields->Codegen();
    if (V == nullptr)
    {
        errors_IR++;
        generateError("ERROR: Invalid field Declarations");
        return nullptr;
    }
    V = methods->Codegen();
    if (V == nullptr)
    {
        errors_IR++;
        generateError("ERROR: Invalid method Declarations");
        return nullptr;
    }       
    return V;
}


Value* meth_decs::Codegen()
{
    Value *V = ConstantInt::get(Context, APInt(32, 0));
    for (auto &i : meth_decs_list) {
        V = i->Codegen();
        if (V == nullptr) return V;
    }
    return V;
}

Value* meth_dec::Codegen()
{
    vector<string> argNames;
    vector<string> argTypes;

    vector<class meth_arg *> args = arg_list->getList();

    vector<Type *> arguments;

    auto arg_size = args.size();

    for (auto &arg : args) {
        string arg_type = arg->getType();
        string arg_name = arg->getName();
        if (arg_type == "int") {
            arguments.push_back(Type::getInt32Ty(Context));
        } else if (arg_type == "boolean") {
            arguments.push_back(Type::getInt1Ty(Context));
        } else {
            errors_IR++;
            generateError("ERROR: Arguments can only be int or boolean");
            return nullptr;
        }
        argTypes.emplace_back(arg_type);
        argNames.emplace_back(arg_name);
    }

    Type *returnType;
    if (return_type == "int") {
        returnType = Type::getInt32Ty(Context);
    } else if (return_type == "boolean") {
        returnType = Type::getInt1Ty(Context);
    } else if (return_type == "void") {
        returnType = Type::getVoidTy(Context);
    } else {
        errors_IR++;
        generateError("ERROR: Invalid Return Type for " + name + ". Return Type can only be int or boolean or bool");
        return nullptr;
    } 

    FunctionType *FT = FunctionType::get(returnType, arguments, false);
    Function *F = Function::Create(FT, Function::ExternalLinkage, name, TheModule);


    unsigned Idx = 0;
    for (Function::arg_iterator AI = F->arg_begin(); Idx != arg_size; ++AI, ++Idx) {
        AI->setName(argNames[Idx]);
    }

    BasicBlock *BB = BasicBlock::Create(Context, "entry", F);
    Builder.SetInsertPoint(BB);
    Idx = 0;      

    for (auto &Arg : F->args()) {
        AllocaInst *Alloca = CreateEntryBlockAlloca(F, argNames[Idx], argTypes[Idx]);
        Builder.CreateStore(&Arg, Alloca);
        NamedValues[argNames[Idx]] = Alloca;
        Idx++;
    }

    Value *RetVal = body->Codegen();

    if(RetVal==nullptr)
    {
        if(return_type=="void")
            Builder.CreateRetVoid();

        if(return_type == "boolean" or return_type == "int")
        {
            errors_IR++;
            generateError("ERROR: Invalid Return Type for " + name + ". Return Type can only be " + return_type + " as defined");
        }    

        verifyFunction(*F);
        return F;
    }

    if (RetVal) {
        // cout << RetVal->getType()->isVoidTy()  << " type "  << endl; 
        if (return_type == "void")
        {
            Builder.CreateRetVoid();

            // if(RetVal->getType()->isIntegerTy(32) || RetVal->getType()->isIntegerTy(32))
            // {
            //     errors_IR++;
            //     generateError("ERROR: Invalid Return Type for " + name + ". Return Type can only be void as defined");
            //     return nullptr;
            // }

        }
        else
        {
            if(!RetVal->getType()->isIntegerTy(32) and return_type == "int")
            {
                errors_IR++;
                generateError("ERROR: Invalid Return Type for " + name + ". Return Type can only be int as defined");
                return nullptr;
            }

            if(!RetVal->getType()->isIntegerTy(1) and return_type == "boolean")
            {
                errors_IR++;                
                generateError("ERROR: Invalid Return Type for " + name + ". Return Type can only be int as defined");
                return nullptr;
            }       

        }

        verifyFunction(*F);
        return F;
    }    


    F->eraseFromParent();
    return nullptr;
}

Value* Block::Codegen()
{
    Value *V;
    map<string, AllocaInst *> Old_vals;
    V = declarations_list->Codegen(Old_vals);
    if (V == nullptr) {
        return V;
    }
    V = statements_list->Codegen();
    for (auto it = Old_vals.begin(); it != Old_vals.end(); it++) {
        NamedValues[it->first] = Old_vals[it->first];
    }
    return V;    
}

Value* Statements::Codegen()
{
    Value *v = ConstantInt::get(Context, llvm::APInt(32, 1));
    for (auto &stmt : statements_list) {
        v = stmt->Codegen();
    }
    return v;
}

// Value* meth_call::Codegen_check_return()
// {

//     Function *calle = TheModule->getFunction(name);
//     if (calle == nullptr) {
//         errors_IR++;
//         return generateError("Unknown Function name" + name);
//     }
//     /* Check if required number of parameters are passed */
//     vector<class Expr *> args_list = params->getParams();
//     if (calle->arg_size() != args_list.size()) {
//         errors_IR++;
//         return generateError("Incorrect Number of Parameters Passed");
//     }
    
//     FunctionType *FTy = calle->getFunctionType();

//     if(calle->getReturnType()->isVoidTy())
//     {
//         errors_IR++;
//         generateError("Function " + name + " must return a value for Expr");
//     }

//     for(int i=0; i<args_list.size(); i++)
//     {
//         Value *argVal = args_list[i]->Codegen();
//         if (args_list[i]->getEtype() == ::location) {
//             argVal = Builder.CreateLoad(argVal);
//         }
//         if (argVal == nullptr) {
//             errors_IR++;
//             generateError("Argument is not valid");
//         }

//         if(argVal->getType() != FTy->getParamType(i))
//         {
//             return generateError("Incorrect type found");
//         }

//     }
//     /// Generate the code for the arguments
//     vector<Value *> Args;
//     for (auto &arg : args_list) {
//         Value *argVal = arg->Codegen();
//         if (arg->getEtype() == ::location) {
//             argVal = Builder.CreateLoad(argVal);
//         }
//         if (argVal == nullptr) {
//             errors_IR++;
//             generateError("Argument is not valid");
//         }
//         Args.push_back(argVal);
//     }
//     // Reverse the order of arguments as the parser parses in the reverse order
//     // reverse(Args.begin(), Args.end());
//     // Generate the code for the function call
//     Value *v = Builder.CreateCall(calle, Args);
//     return v;
// }

Value* meth_call::Codegen()
{

    Function *calle = TheModule->getFunction(name);
    if (calle == nullptr) {
        errors_IR++;
        return generateError("ERROR: Unknown Function name" + name);
    }

    vector<class Expr *> args_list = params->getParams();
    if (calle->arg_size() != args_list.size()) {
        errors_IR++;
        return generateError("ERROR: Incorrect Number of Parameters Passed");
    }
    
    FunctionType *FTy = calle->getFunctionType();
    // cout << FTy->getParamType(0) << " -a ada\n";

    // if(calle->getReturnType()->isVoidTy())
    // {
    //     errors_IR++;
    //     generateError("Function " + name + " must return a value for Expr");
    // }

    for(int i=0; i<args_list.size(); i++)
    {
        Value *argVal = args_list[i]->Codegen();
        if (args_list[i]->getEtype() == ::location) {
            argVal = Builder.CreateLoad(argVal);
        }
        if (argVal == nullptr) {
            errors_IR++;
            generateError("ERROR: Argument is not valid");
        }

        if(argVal->getType() != FTy->getParamType(i))
        {
            errors_IR++;
            return generateError("ERROR: Incorrect type found in passing " + name + " function parameters");
        }

    }

    vector<Value *> Args;
    for (auto &arg : args_list) {
        Value *argVal = arg->Codegen();
        if (arg->getEtype() == ::location) {
            argVal = Builder.CreateLoad(argVal);
        }
        if (argVal == nullptr) {
            errors_IR++;
            generateError("ERROR: Argument is not valid");
        }
        Args.push_back(argVal);
    }

    Value *v = Builder.CreateCall(calle, Args);
    return v;
}



Value *BinExpr::Codegen() {
    Value *left = NULL;
    Value *right = NULL;

    left = lhs->Codegen();

    right = rhs->Codegen();

    if (lhs->getEtype() == ::location) {
        left = Builder.CreateLoad(left);
    }
    if (rhs->getEtype() == ::location) {
        right = Builder.CreateLoad(right);
    }
    if (left == 0) {
        errors_IR++;
        return generateError("ERROR: Error in left operand of " + op);
    } else if (right == 0) {
        errors_IR++;
        return generateError("ERROR: Error in right operand of " + op);
    }

    if( op!= "==" && op!= "!=" && op != "&&" && op != "||" && !(left->getType()->isIntegerTy(32) && right->getType()->isIntegerTy(32)))
    {
        errors_IR++;
        return generateError("ERROR: operand " + op + " must have integers on both sides");
    }

    if((op == "==" || op== "!=") && !((left->getType()->isIntegerTy(32) == right->getType()->isIntegerTy(32)) || (left->getType()->isIntegerTy(1) == right->getType()->isIntegerTy(1)) ))
    {
        errors_IR++;
        return generateError("ERROR: operand " + op + " must have either integers/booleans on both sides");
    }


    if( (op== "||" || op== "&&") && !(left->getType()->isIntegerTy(1) && right->getType()->isIntegerTy(1)))
    {
        errors_IR++;
        return generateError("ERROR:  operand " + op + " must have booleans on both sides");
    }    

    Value *v = nullptr;
    if (op == "+") {
        v = Builder.CreateAdd(left, right, "addition");
    } else if (op == "-") {
        v = Builder.CreateSub(left, right, "subtraction");
    } else if (op == "*") {
        v = Builder.CreateMul(left, right, "multiplication");
    } else if (op == "/") {
        v = Builder.CreateSDiv(left, right, "division");
    } else if (op == "%") {
        v = Builder.CreateSRem(left, right, "modulus");
    } else if (op == "<") {
        v = Builder.CreateICmpSLT(left, right, "ltcompare");
    } else if (op == ">") {
        v = Builder.CreateICmpSGT(left, right, "gtcompare");
    } else if (op == "<=") {
        v = Builder.CreateICmpSLE(left, right, "lecompare");
    } else if (op == ">=") {
        v = Builder.CreateICmpSGE(left, right, "gecompare");
    } else if (op == "==") {
        v = Builder.CreateICmpEQ(left, right, "equalcompare");
    } else if (op == "!=") {
        v = Builder.CreateICmpNE(left, right, "notequalcompare");
    }
    else if (op == "||") {
        return Builder.Insert(BinaryOperator::Create(Instruction::Or, left, right, "doubleor"));
    } 
    else if (op == "&&") {
        return Builder.Insert(BinaryOperator::Create(Instruction::And, left, right, "doubleand"));
    }     
    return v;
}

Value *UnExpr::Codegen() {

    Value *v = exp->Codegen();
    if (exp->getEtype() == ::location) {
        v = Builder.CreateLoad(v);
    }
    if (op == "-") {
        return Builder.CreateNeg(v, "negation");
    }
    if(!(v->getType()->isIntegerTy(1)))
    {
        errors_IR++;
        return generateError("ERROR:  operand " + op + " must have boolean.");
    } 
        return Builder.CreateNot(v, "notop");
}

Value *breakState::Codegen() {
    Value *V = ConstantInt::get(Context, APInt(32, 1));
    loopInfo *currentLoop = loops->top();
    Builder.CreateBr(currentLoop->getAfterBlock());

    // cout << loops->size() << "loops size" <<endl;
    if(loops->size() == 0)
    {
        errors_IR++;
        return generateError("ERROR: break must be in for loop only.");
    }

    return V;
}

Value *returnState::Codegen() {
    Value *V = nullptr;
    if (ret != nullptr) {
        V = ret->Codegen();
        if (ret->getEtype() == ::location) {
            V = Builder.CreateLoad(V);
        }
        Builder.CreateRet(V);
        return V;
    }
    // cout << "here generated void return \n";
    Builder.CreateRetVoid();
    return V;
}


Value *calloutArg::Codegen() {
    if (expr == nullptr) {
        errors_IR++;
        return generateError("ERROR: Invalid Callout Arg");
    }
    Value *v = expr->Codegen();
    if (expr->getEtype() == ::location) {
        v = Builder.CreateLoad(v);
    }
    return v;
}

Value *callout_call::Codegen() {

    vector<Type *> argTypes;
    vector<Value *> Args;
    vector<class calloutArg *> args_list = args->getArgs();

    for (auto &i : args_list) {
        Value *tmp = i->Codegen();
        if (tmp == nullptr) {
            return nullptr;
        }
        Args.push_back(tmp);
        argTypes.push_back(tmp->getType());
    }

    ArrayRef<Type *> argsRef(argTypes);
    ArrayRef<Value *> funcargs(Args);
    FunctionType *FType = FunctionType::get(Type::getInt32Ty(Context), argsRef, false);
    Constant *func = TheModule->getOrInsertFunction(name, FType);

    if (!func) {
        errors_IR++;
        return generateError("ERROR:  in inbuilt function. Unknown Function name " + name);
    }
    Value *v = Builder.CreateCall(func, funcargs);
    return v;
}

Value *continueState::Codegen() {
    Value *V = ConstantInt::get(Context, llvm::APInt(32, 1));
    loopInfo *currentLoop = loops->top();
    string var = currentLoop->getLoopVariable();
    AllocaInst *Alloca = NamedValues[var];
    Value *step_val = ConstantInt::get(Context, APInt(32, 1));
    Value *cur = Builder.CreateLoad(Alloca, var);
    Value *next_val = Builder.CreateAdd(cur, step_val, "NextVal");
    Builder.CreateStore(next_val, Alloca);
    Value *cond = Builder.CreateICmpULE(next_val, currentLoop->getCondition(),"loopcondition");
    BasicBlock *loopEndBlock = Builder.GetInsertBlock();
    Builder.CreateCondBr(cond, currentLoop->getCheckBlock(), currentLoop->getAfterBlock());
    return V;
}

Value *EncExpr::Codegen()
{
    return expr->Codegen();
}

Value *forState::Codegen() {

    Value *start = init->Codegen();
    if (start == nullptr) {
        return nullptr;
    }
    if (init->getEtype() == ::location) {
        start = Builder.CreateLoad(start);
    }

    if(!(start->getType()->isIntegerTy(32)))
    {
        errors_IR++;
        return generateError("ERROR:  For loop initial expr must have type integer");
    }    

    Function *TheFunction = Builder.GetInsertBlock()->getParent();
    llvm::AllocaInst *Alloca = CreateEntryBlockAlloca(TheFunction, var, string("int"));
    Builder.CreateStore(start, Alloca);

    Value *step_val = ConstantInt::get(Context, APInt(32, 1));
    BasicBlock *pre_header_basic_block = Builder.GetInsertBlock();
    BasicBlock *loop_body = BasicBlock::Create(Context, "loop", TheFunction);
    BasicBlock *afterBB = BasicBlock::Create(Context, "afterloop", TheFunction);
    Builder.CreateBr(loop_body);
    Builder.SetInsertPoint(loop_body);

    PHINode *Variable = Builder.CreatePHI(Type::getInt32Ty(Context), 2, var);
    Variable->addIncoming(start, pre_header_basic_block);
    Value *cond = end_cond->Codegen();
    if (cond == nullptr) {
        errors_IR++;
        return generateError("ERROR: Invalid Condition");
    }    

    if (end_cond->getEtype() == ::location) {
        cond = Builder.CreateLoad(cond);
    }

    if(!(cond->getType()->isIntegerTy(32)))
    {
        errors_IR++;
        return generateError("ERROR:  For loop ending expr must have type integer");
    }   

    loops->push(new loopInfo(afterBB, loop_body, cond, var, Variable));
    llvm::AllocaInst *OldVal = NamedValues[var];
    NamedValues[var] = Alloca;

    if (body->Codegen() == nullptr) {
        return nullptr;
    }

    Value *cur = Builder.CreateLoad(Alloca, var);
    Value *next_val = Builder.CreateAdd(cur, step_val, "NextVal");
    Builder.CreateStore(next_val, Alloca);
    cond = Builder.CreateICmpSLT(next_val, cond, "loopcondition");
    BasicBlock *loopEndBlock = Builder.GetInsertBlock();
    Builder.CreateCondBr(cond, loop_body, afterBB);
    Builder.SetInsertPoint(afterBB);
    Variable->addIncoming(next_val, loopEndBlock);

    if (OldVal) {
        NamedValues[var] = OldVal;
    } else {
        NamedValues.erase(var);
    }
    llvm::Value *V = ConstantInt::get(Context, APInt(32, 1));
    return V;

}  

Value *ifElseState::Codegen() {

    Value *cond = this->cond->Codegen();
    if (cond == nullptr) {
        errors_IR++;
        return generateError("ERROR: Invalid Expression in the IF");
    }

    if(!cond->getType()->isIntegerTy(1))
    {
        errors_IR++;
        return generateError("ERROR: Condition in IF must be of boolean type");        
    }

    Function *TheFunction = Builder.GetInsertBlock()->getParent();
    BasicBlock *ifBlock = BasicBlock::Create(Context, "if", TheFunction);
    BasicBlock *elseBlock = BasicBlock::Create(Context, "else");
    BasicBlock *nextBlock = BasicBlock::Create(Context, "ifcont");
    BasicBlock *otherBlock = elseBlock;
    bool ret_if = if_block->has_return(), ret_else = false;
    bool break_if = if_block->has_break(), break_else = false;
    bool continue_if = if_block->has_continue(), continue_else = false;

    if (else_block == nullptr) {
        otherBlock = nextBlock;
    }
    Builder.CreateCondBr(cond, ifBlock, otherBlock);
    Builder.SetInsertPoint(ifBlock);

    Value *if_val = if_block->Codegen();
    if (if_val == nullptr) {
        return nullptr;
    }

    if (!ret_if && !break_if && !continue_if) {
        Builder.CreateBr(nextBlock);
    }

    ifBlock = Builder.GetInsertBlock();

    Value *else_val = nullptr;

    if (else_block != nullptr) {
        TheFunction->getBasicBlockList().push_back(elseBlock);
        Builder.SetInsertPoint(elseBlock);
        else_val = else_block->Codegen();
        if (else_val == nullptr) {
            return nullptr;
        }
        ret_else = else_block->has_return();
        break_else = else_block->has_break();
        continue_else = else_block->has_continue();

        if (!ret_else && !break_else && !continue_else)
            Builder.CreateBr(nextBlock);
    }

    TheFunction->getBasicBlockList().push_back(nextBlock);
    Builder.SetInsertPoint(nextBlock);
    if (ret_else && ret_if) {
        Type *retType = Builder.GetInsertBlock()->getParent()->getReturnType();
        if (retType == Type::getVoidTy(Context))
            Builder.CreateRetVoid();
        else {
            Builder.CreateRet(ConstantInt::get(Context, APInt(32, 0)));
        }
    }
    Value *V = ConstantInt::get(Context, APInt(32, 0));
    return V;    
}

Value *Location::invalidArrayIndex() {
    errors_IR++;
    return generateError("ERROR: Invalid array index");
}

Value *Location::Codegen() {

    Value *V = NamedValues[var];
    if (V == nullptr) {
        V = TheModule->getNamedGlobal(var);
    }
    if (V == nullptr) {
        errors_IR++;
        return generateError("ERROR: Unknown Variable name " + var);
    }

    if (this->location_type == ::variable) {
        return V;
    }

    Type* chech_type = V->getType();

    if (PointerType *pointerType = dyn_cast<PointerType>(chech_type)) {
        Type* elementType = pointerType->getElementType();

        if (!elementType->isArrayTy()) {
            errors_IR++;
            return generateError("ERROR: Unknown Array name " + var);                
        }
    }        

    if (this->array_index == nullptr) {
        return invalidArrayIndex();
    }
    Value *index = array_index->Codegen();
    if (array_index->getEtype() == ::location) {
        index = Builder.CreateLoad(index);
    }


    if(!(index->getType()->isIntegerTy(32)))
    {
        errors_IR++;
        return generateError("ERROR: for array " + var + " give integer as index.");
    }

    if (index == nullptr) {
        return invalidArrayIndex();
    }

    vector<Value *> array_index;
    array_index.push_back(Builder.getInt32(0));
    array_index.push_back(index);
    V = Builder.CreateGEP(V, array_index, var + "_Index");
    return V;
}



Value *Assign::Codegen() {

    Value *cur = NamedValues[loc->getName()];
    if (cur == nullptr) {
        cur = TheModule->getGlobalVariable(loc->getName());
    }
    if (cur == nullptr) {
        errors_IR++;
        return generateError("ERROR: Unknown Variable Name " + loc->getName());
    }

    Value *val = NULL;
    
    val = exp->Codegen();

    if (exp->getEtype() == ::location) {
        val = Builder.CreateLoad(val);
    }

    Value *lhs = loc->Codegen();
    cur = Builder.CreateLoad(lhs);

    if (val == nullptr) {
        errors_IR++;
        return generateError("ERROR: Error in right hand side of the Assignment");
    }

 
    if(!((cur->getType()->isIntegerTy(1) && val->getType()->isIntegerTy(1)) || (cur->getType()->isIntegerTy(32) && val->getType()->isIntegerTy(32)) ))
    {
        errors_IR++;
        return generateError("ERROR:  both sides of assignment op " + op + " must have same type.");        
    }

    if( op != "=" && !(cur->getType()->isIntegerTy(32)) && !(val->getType()->isIntegerTy(32)) )
    {
        errors_IR++;
        return generateError("ERROR:  both sides of assignment op " + op + " must be integer type.");        
    }    
    
    if (op == "+=") {
        val = Builder.CreateAdd(cur, val, "addEqualTo");
    } else if (op == "-=") {
        val = Builder.CreateSub(cur, val, "subEqualTo");
    }
    return Builder.CreateStore(val, lhs);
}


Value *var_decs::Codegen(map<string, AllocaInst *> &oldValues) {

    Value *v = ConstantInt::get(Context, APInt(32, 1));
    for (auto &decl : var_decs_list) {

        v = decl->Codegen(oldValues);
        if (v == nullptr) {
            return v;
        }
    }
    return v;
}

Value *var_dec::Codegen(map<string, AllocaInst *> &Old_vals)
{
    Value *V_test;

    llvm::Function *TheFunction = Builder.GetInsertBlock()->getParent();
    for (const auto &var : var_list) {
        llvm::Value *initval = nullptr;
        llvm::AllocaInst *Alloca = nullptr;
        if (type == "int") {

            V_test = NamedValues[var];
            // if (V_test == nullptr) {V_test = TheModule->getNamedGlobal(var);}
            
            // if (V_test != nullptr) { errors_IR++; return generateError("ERROR:  Variable " + var + " already declared"); }

            initval = ConstantInt::get(Context, APInt(32, 0));
            Alloca = CreateEntryBlockAlloca(TheFunction, var, "int");
        } else if (type == "boolean") {

            V_test = NamedValues[var];
            // if (V_test == nullptr) {V_test = TheModule->getNamedGlobal(var);}
            if (V_test != nullptr) { errors_IR++; return generateError("ERROR: Variable " + var + " already declared"); }

            initval = ConstantInt::get(Context, APInt(1, 0));
            Alloca = CreateEntryBlockAlloca(TheFunction, var, "boolean");
        }
        Builder.CreateStore(initval, Alloca);

        Old_vals[var] = NamedValues[var];
        NamedValues[var] = Alloca;

    }
    Value *v = ConstantInt::get(Context, APInt(32, 1));
    return v;    
}

Value* integerLit::Codegen()
{
    Value *v = ConstantInt::get(Context, APInt(32, static_cast<uint64_t>(value)));
    return v;
}  

Value* charLit::Codegen()
{
    Value *v = ConstantInt::get(Context, APInt(32, static_cast<uint64_t>(value)));
    return v;
}  


Value *stringLit::Codegen() {
    return Builder.CreateGlobalStringPtr(value);
}

Value* boolLit::Codegen()
{
    bool now;
    if(value == "true")
        now = 1;
    else
        now = 0;
    return ConstantInt::get(Context, llvm::APInt(1, now));
} 

Value* FieldDecList::Codegen()
{
    for (auto &i : declaration_list) {
        i->Codegen();
    }

    Value *v = ConstantInt::get(Context, APInt(32, 1));
    return v;
}

Value* FieldDec::Codegen()
{
    Type *ty = nullptr;
    Value* V_test;
    if (datatype == "int")
        ty = Type::getInt32Ty(Context);
    else if (datatype == "boolean")
        ty = Type::getInt1Ty(Context);

    for (auto var : var_list) {
        if (var->isArray())
        {

            V_test = TheModule->getNamedGlobal(var->getName());
            if (V_test != nullptr) { errors_IR++; return generateError("ERROR:  Variable " + var->getName() + " already declared"); }

            ArrayType *arrType = ArrayType::get(ty, var->getLength());
            GlobalVariable *gv = new GlobalVariable(*(TheModule), arrType, false, GlobalValue::ExternalLinkage, nullptr, var->getName());
            gv->setInitializer(ConstantAggregateZero::get(arrType));

        } 
        else
        {
            V_test = TheModule->getNamedGlobal(var->getName());
            if (V_test != nullptr) { errors_IR++; return generateError("ERROR:  Variable " + var->getName() + " already declared"); }

            GlobalVariable *gv = new GlobalVariable(*(TheModule), ty, false, GlobalValue::ExternalLinkage, nullptr, var->getName());
            gv->setInitializer(Constant::getNullValue(ty));
        }
    }
    Value *v = ConstantInt::get(Context, APInt(32, 1));
    return v;
}
