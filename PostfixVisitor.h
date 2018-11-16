#include "ast.h"

class PostFixVisitor: public ASTvisitor {
    public:

    virtual void visit(ProgramASTnode& node) 
    {
        cout << "Class " << node.getProgramName() << " declared\n";

        class FieldDecList* fields = node.getFields();
        fields->accept(*this);

        class meth_decs* methods = node.getMeths();
        methods->accept(*this);

    }

    virtual void visit(FieldDecList& node) 
    {
        // cout << "FieldDecList " << " declared\n";

        vector<class FieldDec *> fieldslist = node.getList();

        for(auto& i: fieldslist)
        {
            i->accept(*this);
        }

    }

    virtual void visit(FieldDec& node) 
    {
        // cout << "FieldDec " << " declared\n";

        cout << node.getType() << " - ";

        vector<class Variable *> var_list = node.getVarsList();

        for(auto& i: var_list)
        {
            if(i->isArray())
                cout << i->getName() << "[" << i->getLength() << "]" << " ";
            else
                cout << i->getName() << " ";
        }
        
        cout << endl;

    }

    virtual void visit(Variable& node) 
    {
        cout << "Variable " << " declared\n";
    }

    virtual void visit(Variables& node) 
    {
        cout << "Variables " << " declared\n";
    }

    virtual void visit(Expr& node) 
    {
        cout << "Expr " << " declared\n";
    }            

    virtual void visit(Lit& node) 
    {
        cout << "Lit " << " declared\n";
    }      

    virtual void visit(integerLit& node) 
    {
        // cout << "integerLit " << " declared\n";
        cout << node.getValue();
    }     

    virtual void visit(boolLit& node) 
    {
        // cout << "boolLit " << " declared\n";
        cout << node.getVal();
    }     

    virtual void visit(charLit& node) 
    {
        // cout << "charLit " << " declared\n";
        cout << node.getVal();
    }             

    virtual void visit(Block& node) 
    {
        // cout << "Block " << " declared ";

        class var_decs* var_decl = node.get_var_decs();
        var_decl->accept(*this);
        
        node.init_mymap(var_decl);
        // node.print_mymap();

        // cout << "vars decs ";
        
        class Statements *statements_list = node.get_states();
        statements_list->set_scope_map(node.mymap);
        statements_list->accept(*this);  
        
        // cout << "statement decs ";
        cout << endl; 

    }

    virtual void visit(meth_arg& node) 
    {
        // cout << "meth_arg " << " declared\n";
        cout << node.getType() << "-" << node.getName() << " ";
    }            

    virtual void visit(meth_args& node) 
    {
        // cout << "meth_args " << " declared\n";
        vector<class meth_arg *> meth_args_list = node.getList();
        for(auto& i: meth_args_list)
        {
            i->accept(*this);
        } 
    }         

    virtual void visit(meth_dec& node) 
    {
        // cout << "meth_dec " << " declared\n";
        cout << "Meth " << node.getName() << " - ";
        cout << node.getType() << " - ";
        class meth_args * args = node.getArgs();
        args->accept(*this);
        cout << " - ";
        class Block *body = node.getBlock();
        body->add_to_mymap(args->arg_list);
        body->accept(*this);
    
    }      

    virtual void visit(meth_decs& node) 
    {
        // cout << "meth_decs " << " declared\n";
        vector<class meth_dec *> methods = node.getList();
        for(auto& i: methods)
        {
            i->accept(*this);
        }        

    }     

    virtual void visit(Statement& node) 
    {
        cout << "Statement " << " declared\n";
    }     

    virtual void visit(Statements& node) 
    {
        // cout << "Statements " << " declared\n";
        vector<class Statement *> statements_list = node.getList();
        for(auto& i: statements_list)
        {            
            i->accept(*this);
        }                   
    }             

    virtual void visit(var_decs& node) 
    {
        // cout << "var_decs " << " declared\n";
        vector<class var_dec *> var_decs_list = node.getList();
        for(auto& i: var_decs_list)
        {
            i->accept(*this);
        }             

    }     

    virtual void visit(var_dec& node) 
    {
        // cout << "var_dec " << " declared\n";
        vector<string> var_list = node.getList();
        cout << "vardecs - " << node.getType() << " ";
        for(auto& i: var_list)
        {
            cout << i << ", " ;
        }                  
        cout << " - ";

    }  

    virtual void visit(meth_call& node) 
    {
        // cout << "meth_call " << " declared\n";
        cout << node.getName() << "(";
        class Parameters* params = node.getParams();
        params->accept(*this);
        cout << ")";

    }     

    virtual void visit(BinExpr& node) 
    {
        // cout << "BinExpr " << " declared\n";
        class Expr *lhs = node.getLhs();
        class Expr *rhs = node.getRhs();
        string op = node.getOp();

        lhs->accept(*this);
        cout << op;
        rhs->accept(*this);

    }      

    virtual void visit(UnExpr& node) 
    {
        // cout << "UnExpr " << " declared\n";
        class Expr *expr = node.getExp();
        string op = node.getOp();
        
        cout << op;
        expr->accept(*this);

    }                 

    virtual void visit(EncExpr& node) 
    {
        // cout << "EncExpr " << " declared\n";
        class Expr *expr = node.getexpr();
        cout << "(";
        expr->accept(*this);
        cout << ")";
    }             

    virtual void visit(Parameters& node)
    {
        // cout << "Parameters " << " declared\n";
        vector<class Expr *> params = node.getParams();
        // cout << params.size() ;
        for(auto& i: params)
        {
            i->accept(*this);
            cout << ",";
        }                  

    }

    virtual void visit(stringLit& node) 
    {
        // cout << "stringLit " << " declared\n";
        cout << node.getVal();
    }     

    virtual void visit(calloutArgs& node) 
    {
        // cout << "calloutArgs " << " declared\n";
        vector<class calloutArg *> args = node.getArgs();
        for(auto& i: args)
        {
            i->accept(*this);
            cout << ",";
        }       
    }     

    virtual void visit(calloutArg& node) 
    {
        // cout << "calloutArg " << " declared\n";
        class Expr *expr = node.getExpr();
        expr->accept(*this);
    }     

    virtual void visit(callout_call& node) 
    {
        // cout << "callout_call " << " declared\n";
        cout << " callout(";
        class calloutArgs *args = node.getArgs();
        args->accept(*this);
        cout << " ) ";
    } 

    virtual void visit(breakState& node) 
    {
        cout << " breakState " << " declared ";
    }       

    virtual void visit(continueState& node) 
    {
        cout << " continueState " << " declared ";
    }    

    virtual void visit(returnState& node) 
    {
        // cout << " returnState " << " declared ";
        cout << " return ";
        if(node.hasReturn())
        {
            class Expr * ret = node.getRet();
            ret->accept(*this);
        }
        cout << "; ";

    }        

    virtual void visit(forState& node) 
    {
        // cout << " forState " << " declared ";
        node.add_scope_map(node.var, "int");
        // node.print_scope_map();
        cout << " for " << node.getVar() << ": ";
        class Expr * init = node.getInit();
        class Expr * end_cond = node.getEnd();
        class Block* body = node.getBody();
        init->accept(*this);
        cout << " - ";
        end_cond->accept(*this);
        cout << "{";
        body->accept(*this);
        // cout << "Here";
        cout << "} ";

    }    

    virtual void visit(ifElseState& node) 
    {
        // cout << " ifElseState " << " declared ";
        // node.print_scope_map();
        cout << " if(";
        class Expr* cond = node.getCond();
        class Block* if_block = node.getIf();
        class Block* else_block = node.getElse();
        cond->accept(*this);
        cout << "){";
        if_block->accept(*this);
        cout << "} ";
        if(node.getElsePre())
        {
            cout <<"else {";
            else_block->accept(*this);
            cout << "} ";
        }

    } 


    virtual void visit(Location& node) 
    {
        // cout << " Location " << " declared ";
        cout << node.getName();
        if(node.isArray())
        {
            class Expr *array_index = node.getIndex();
            cout << "[";
            array_index->accept(*this);
            cout << "]";
        }
        cout << " ";
    }    


    virtual void visit(Assign& node) 
    {
        // cout << " Assign " << " declared ";
        class Location *loc = node.getLoc();
        class Expr * exp = node.getRet();
        loc->accept(*this);
        cout << node.getOp();
        exp->accept(*this);
        cout << " ";   
    }   

};