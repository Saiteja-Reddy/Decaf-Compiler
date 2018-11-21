#include "ast.h"
using namespace std;

AllocaInst *CreateEntryBlockAlloca(Function *TheFunction, string VarName, string type) {
    /* Get the builder for current context */
    IRBuilder<> TmpB(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
    AllocaInst *alloca_instruction = nullptr;
    if (type == "int") {
        alloca_instruction = TmpB.CreateAlloca(Type::getInt32Ty(Context), 0, VarName);
    } else if (type == "boolean") {
        alloca_instruction = TmpB.CreateAlloca(Type::getInt1Ty(Context), 0, VarName);
    }
    return alloca_instruction;
}

Value* ASTnode::Codegen()
{
    return nullptr;
}

Value* ProgramASTnode::Codegen()
{
    Value *V;
    cout << "Now generating code\n";
    V = fields->Codegen();
    if (V == nullptr)
    {
        cout << "Invalid field Declarations\n";
        // reportError("Invalid field Declarations");
        return nullptr;
    }
    cout << "Done field Declarations\n";
    V = methods->Codegen();
    if (V == nullptr)
    {
        cout << "Invalid method Declarations\n";
        // reportError("Invalid method Declarations");
        return nullptr;
    }       
    cout << "Done method Declarations\n"; 
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
            // reportError("Arguments can only be int or boolean");
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
        // reportError("Invalid Return Type for " + name + ". Return Type can only be int or boolean or bool");
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
    if (RetVal) {
        if (return_type != "void")
            Builder.CreateRet(RetVal);
        else
            Builder.CreateRetVoid();

        verifyFunction(*F);
        // TheFPM->run(*F);
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
    /* Adjust the values back to old values */
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

Value* meth_call::Codegen()
{

    Function *calle = TheModule->getFunction(name);
    if (calle == nullptr) {
        errors_IR++;
        return nullptr;
        // return reportError("Unknown Function name" + name);
    }
    /* Check if required number of parameters are passed */
    vector<class Expr *> args_list = params->getParams();
    if (calle->arg_size() != args_list.size()) {
        errors_IR++;
        return nullptr;
        // return reportError("Incorrect Number of Parameters Passed");
    }
    /// Generate the code for the arguments
    vector<Value *> Args;
    for (auto &arg : args_list) {
        Value *argVal = arg->Codegen();
        if (arg->getEtype() == ::location) {
            argVal = Builder.CreateLoad(argVal);
        }
        if (argVal == nullptr) {
            errors_IR++;
            // reportError("Argument is not valid");
            return nullptr;
        }
        Args.push_back(argVal);
    }
    // Reverse the order of arguments as the parser parses in the reverse order
    reverse(Args.begin(), Args.end());
    // Generate the code for the function call
    Value *v = Builder.CreateCall(calle, Args);
    return v;

}

Value *BinExpr::Codegen() {
    Value *left = lhs->Codegen();
    Value *right = rhs->Codegen();
    if (lhs->getEtype() == ::location) {
        left = Builder.CreateLoad(left);
    }
    if (rhs->getEtype() == ::location) {
        right = Builder.CreateLoad(right);
    }
    if (left == 0) {
        errors_IR++;
        return nullptr;
        // return reportError("Error in left operand of " + op);
    } else if (right == 0) {
        errors_IR++;
        return nullptr;
        // return reportError("Error in right operand of " + op);
    }
    Value *v = nullptr;
    if (op == "+") {
        v = Builder.CreateAdd(left, right, "addtmp");
    } else if (op == "-") {
        v = Builder.CreateSub(left, right, "subtmp");
    } else if (op == "*") {
        v = Builder.CreateMul(left, right, "multmp");
    } else if (op == "/") {
        v = Builder.CreateSDiv(left, right, "divtmp");
    } else if (op == "%") {
        v = Builder.CreateSRem(left, right, "modtmp");
    } else if (op == "<") {
        v = Builder.CreateICmpSLT(left, right, "ltcomparetmp");
    } else if (op == ">") {
        v = Builder.CreateICmpSGT(left, right, "gtcomparetmp");
    } else if (op == "<=") {
        v = Builder.CreateICmpSLE(left, right, "lecomparetmp");
    } else if (op == ">=") {
        v = Builder.CreateICmpSGE(left, right, "gecomparetmp");
    } else if (op == "==") {
        v = Builder.CreateICmpEQ(left, right, "equalcomparetmp");
    } else if (op == "!=") {
        v = Builder.CreateICmpNE(left, right, "notequalcomparetmp");
    }
    return v;
}

Value *UnExpr::Codegen() {
    /// Generate IR for body of the expression
    Value *v = exp->Codegen();
    if (exp->getEtype() == ::location) {
        v = Builder.CreateLoad(v);
    }
    /// Generate the code for operation based on the operator
    if (op == "-") {
        return Builder.CreateNeg(v, "negtmp");
    }
    // else if (op == "!") {
        return Builder.CreateNot(v, "nottmp");
    // }
}

Value *breakState::Codegen() {
    Value *V = ConstantInt::get(Context, APInt(32, 1));
    loopInfo *currentLoop = loops->top();
    Builder.CreateBr(currentLoop->getAfterBlock());
    return V;
}

Value *returnState::Codegen() {
    Value *V = nullptr;
    if (ret != nullptr) {
        /// Generate IR for expression to be returned
        V = ret->Codegen();
        if (ret->getEtype() == ::location) {
            /// Generate IR for returning it
            V = Builder.CreateLoad(V);
        }
        Builder.CreateRet(V);
        return V;
    }
    Builder.CreateRetVoid();
    return V;
}




Value *calloutArg::Codegen() {
    if (expr == nullptr) {
        errors_IR++;
        return nullptr;
        // return reportEcrror("Invalid Callout Arg");
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
    /**
     * Iterate through the arguments and generate the code required for each one of them
     */
    for (auto &i : args_list) {
        Value *tmp = i->Codegen();
        if (tmp == nullptr) {
            return nullptr;
        }
        Args.push_back(tmp);
        argTypes.push_back(tmp->getType());
    }
    /* Generate the code for the function execution */
    ArrayRef<Type *> argsRef(argTypes);
    ArrayRef<Value *> funcargs(Args);
    FunctionType *FType = FunctionType::get(Type::getInt32Ty(Context), argsRef, false);
    Constant *func = TheModule->getOrInsertFunction(name, FType);
    if (!func) {
        return nullptr;
        // return reportError("Error in inbuilt function. Unknown Function name " + method_name);
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
    /* Get the parent method of this for loop */
    Function *TheFunction = Builder.GetInsertBlock()->getParent();
    /* Create memory for the loop variable */
    AllocaInst *Alloca = CreateEntryBlockAlloca(TheFunction, var, string("int"));
    Builder.CreateStore(start, Alloca);

    Value *step_val = ConstantInt::get(Context, APInt(32, 1));
    BasicBlock *pre_header_basic_block = Builder.GetInsertBlock();
    BasicBlock *loop_body = BasicBlock::Create(Context, "loop", TheFunction);
    BasicBlock *afterBB = BasicBlock::Create(Context, "afterloop", TheFunction);
    Builder.CreateBr(loop_body);
    Builder.SetInsertPoint(loop_body);

    PHINode *Variable = Builder.CreatePHI(Type::getInt32Ty(Context), 2, var);
    Variable->addIncoming(start, pre_header_basic_block);
    /* Store the old value */
    Value *cond = end_cond->Codegen();
    if (cond == nullptr) {
        errors_IR++;
        return nullptr;
        // return reportError("Invalid Condition");
    }

    // Check if condition is a location
    if (end_cond->getEtype() == ::location) {
        cond = Builder.CreateLoad(cond);
    }
    loops->push(new loopInfo(afterBB, loop_body, cond, var, Variable));
    AllocaInst *OldVal = NamedValues[var];
    NamedValues[var] = Alloca;
    /* Generate the code for the body */
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
    Value *V = ConstantInt::get(Context, APInt(32, 1));
    return V;
}

Value *ifElseState::Codegen() {
    /* Generate code for the condition */

    Value *cond = this->cond->Codegen();
    if (cond == nullptr) {
        errors_IR++;
        return nullptr;
        // return reportError("Invalid Expression in the IF");
    }

    /* Create blocks for if, else and next part of the code */
    Function *TheFunction = Builder.GetInsertBlock()->getParent();
    BasicBlock *ifBlock = BasicBlock::Create(Context, "if", TheFunction);
    BasicBlock *elseBlock = BasicBlock::Create(Context, "else");
    BasicBlock *nextBlock = BasicBlock::Create(Context, "ifcont");
    BasicBlock *otherBlock = elseBlock;
    // bool ret_if = if_block->has_return(), ret_else = false;
    /// Create a conditional break and an insert point
    if (else_block == nullptr) {
        otherBlock = nextBlock;
    }
    Builder.CreateCondBr(cond, ifBlock, otherBlock);
    Builder.SetInsertPoint(ifBlock);
    /// generate the code for if block
    Value *if_val = if_block->Codegen();
    if (if_val == nullptr) {
        return nullptr;
    }
    /// Create a break for next part of the code after else block

    // if (!ret_if) {
        Builder.CreateBr(nextBlock);
    // }

    ifBlock = Builder.GetInsertBlock();
    /// Create insert point for else block

    Value *else_val = nullptr;

    if (else_block != nullptr) {
        /// Generate code for else block
        TheFunction->getBasicBlockList().push_back(elseBlock);
        Builder.SetInsertPoint(elseBlock);
        else_val = else_block->Codegen();
        if (else_val == nullptr) {
            return nullptr;
        }
        // ret_else = else_block->has_return();
        // if (!ret_else)
            Builder.CreateBr(nextBlock);
    }
    // Create a break for the next part of the code
    TheFunction->getBasicBlockList().push_back(nextBlock);
    Builder.SetInsertPoint(nextBlock);
    // if (ret_else && ret_if) {
    //     // if both if and else block have a return statement create a dummy instruction to hold a next block
    //     Type *retType = Builder.GetInsertBlock()->getParent()->getReturnType();
    //     if (retType == Type::getVoidTy(Context))
    //         Builder.CreateRetVoid();
    //     else {
    //         Builder.CreateRet(ConstantInt::get(Context, APInt(32, 0)));
    //     }
    // }
    Value *V = ConstantInt::get(Context, APInt(32, 0));
    return V;
}

Value *Location::invalidArrayIndex() {
    errors_IR++;
    return nullptr;
    // return reportError("Invalid array index");
}

Value *Location::Codegen() {
    /* Try to get the value of the variable */
    Value *V = NamedValues[var];
    if (V == nullptr) {
        V = TheModule->getNamedGlobal(var);
    }
    if (V == nullptr) {
        errors_IR++;
        return nullptr;
        // return reportError("Unknown Variable name " + var);
    }
    /* If location is variable return the code generated */
    if (this->location_type == ::variable) {
        return V;
    }
    /* Check if we have an index for array */
    if (this->array_index == nullptr) {
        return invalidArrayIndex();
    }
    /* Generate the code for index of the array */
    Value *index = array_index->Codegen();
    if (array_index->getEtype() == ::location) {
        index = Builder.CreateLoad(index);
    }
    /* If index is invalid then report error */
    if (index == nullptr) {
        return invalidArrayIndex();
    }
    /* Generate the code required for accessing the array at the given index */
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
        return nullptr;
        // return reportError("Unknown Variable Name " + loc->getVar());
    }

    Value *val = exp->Codegen();
    if (exp->getEtype() == ::location) {
        val = Builder.CreateLoad(val);
    }

    Value *lhs = loc->Codegen();
    cur = Builder.CreateLoad(lhs);

    if (val == nullptr) {
        errors_IR++;
        return nullptr;
        // return reportError("Error in right hand side of the Assignment");
    }
    if (op == "+=") {
        val = Builder.CreateAdd(cur, val, "addEqualToTmp");
    } else if (op == "-=") {
        val = Builder.CreateSub(cur, val, "subEqualToTmp");
    }
    return Builder.CreateStore(val, lhs);
}


Value *var_decs::Codegen(map<string, AllocaInst *> &oldValues) {

    Value *v = ConstantInt::get(Context, APInt(32, 1));
    for (auto &decl : var_decs_list) {
        /// Generate the code for each declaration
        v = decl->Codegen(oldValues);
        if (v == nullptr) {
            return v;
        }
    }
    return v;
}

Value *var_dec::Codegen(map<string, AllocaInst *> &Old_vals)
{
    /* Get the function to which this declaration belongs */
    llvm::Function *TheFunction = Builder.GetInsertBlock()->getParent();
    for (const auto &var : var_list) {
        llvm::Value *initval = nullptr;
        llvm::AllocaInst *Alloca = nullptr;
        if (type == "int") {
            initval = ConstantInt::get(Context, APInt(32, 0));
            Alloca = CreateEntryBlockAlloca(TheFunction, var, "int");
        } else if (type == "boolean") {
            initval = ConstantInt::get(Context, APInt(1, 0));
            Alloca = CreateEntryBlockAlloca(TheFunction, var, "boolean");
        }
        Builder.CreateStore(initval, Alloca);
        /* Store the old value to old_vals and new value to named values */
        Old_vals[var] = NamedValues[var];
        NamedValues[var] = Alloca;
    }
    Value *v = ConstantInt::get(Context, APInt(32, 1));
    return v;    
}

Value* integerLit::Codegen()
{
    return ConstantInt::get(Context, llvm::APInt(32, static_cast<uint64_t>(value)));
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
        // cout << i->getType() << endl;
        i->Codegen();
        // cout << "Dones" << endl;
    }
        
    Value *v = ConstantInt::get(Context, APInt(32, 1));
    return v;
}

Value* FieldDec::Codegen()
{
    Type *ty = nullptr;
    if (datatype == "int")
        ty = Type::getInt32Ty(Context);
    else if (datatype == "boolean")
        ty = Type::getInt1Ty(Context);

    for (auto var : var_list) {
        // cout << "Field Dec = " << var->getName() << endl;
        if (var->isArray())
        {
            ArrayType *arrType = ArrayType::get(ty, var->getLength());
            GlobalVariable *gv = new GlobalVariable(*(TheModule), arrType, false, GlobalValue::ExternalLinkage, nullptr, var->getName());
            gv->setInitializer(ConstantAggregateZero::get(arrType));
        } 
        else
        {
            GlobalVariable *gv = new GlobalVariable(*(TheModule), ty, false, GlobalValue::ExternalLinkage, nullptr, var->getName());
            // cout << ty << "\n";
            gv->setInitializer(Constant::getNullValue(ty));
        }
    }
    Value *v = ConstantInt::get(Context, APInt(32, 1));
    return v;
}

map <string, string> check_in_scope(string name, map <string, string> mymap)
{
    map <string, string> output;
    output["name"] = "";
    output["type"] = "";
    output["arr"] = "no";

    if(mymap.count(name))
    {
        output["name"] = name;
        output["type"] = mymap[name];
    }
    else
    {
        if(global_map.count(name))
        {
            output["name"] = name;
            output["type"] = global_map[name];
        }
    }

    return output;
}

void Block::init_mymap(class var_decs * decs)
{
    for(auto& i:decs->mymap)
	{
		mymap[i.first] = i.second;
		scope_map[i.first] = i.second;
	}    
}

void Block::add_to_mymap(map <string, string> in_map)
{
    for(auto& i:in_map)
	{
		mymap[i.first] = i.second;
		scope_map[i.first] = i.second;
	}     
}

