#include "ast.h"
using namespace std;


class PostFixVisitor: public ASTvisitor {
    public:

    virtual void visit(ProgramASTnode& node) 
    {
        cout << "Class " << node.getProgramName() << " declared\n";

        class FieldDecList* fields = node.getFields();
        fields->accept(*this);
        cout << endl;

        // vector<class FieldDec *> fieldslist = fields->getList(); 

        // for(auto& i: fieldslist)
        // {
        //     cout <<  i->getType()   << endl;
        // }

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
            cout << i->getName() << " ";
        }

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
};