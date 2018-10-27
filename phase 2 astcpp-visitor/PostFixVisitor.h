#include "ast.h"

class PostFixVisitor: public ASTvisitor {
    public:

    virtual void visit(BinaryASTnode& node)
    {
        node.getLeft()->accept(*this);
        node.getRight()->accept(*this);
        std::cout << node.getBin_operator() << " ";
    }

    virtual void visit(TernaryASTnode& node)
    {
        node.getFirst()->accept(*this);
        node.getSecond()->accept(*this);
        node.getThird()->accept(*this);
        std::cout << "? ";
    }

    virtual void visit(IntLitASTnode& node) 
    {
        std::cout << node.getIntLit() << " ";
    }

    virtual void visit(ProgramASTnode& node) 
    {
        std::cout << "Class " << node.getProgramName() << " declared\n";
    }


};