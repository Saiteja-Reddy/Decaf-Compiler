#include "ast.h"
using namespace std;


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
        cout << "integerLit " << " declared\n";
    }     

    virtual void visit(Block& node) 
    {
        // cout << "Block " << " declared\n";

        class var_decs* var_decl = node.get_var_decs();
        var_decl->accept(*this);
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
        cout << "Statements " << " declared\n";
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



};