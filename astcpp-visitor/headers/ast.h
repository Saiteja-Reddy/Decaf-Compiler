
class BinaryASTnode;
class TernaryASTnode;
class IntLitASTnode;

class ASTvisitor {
  public:
    virtual void visit(BinaryASTnode& node) = 0;
    virtual void visit(TernaryASTnode& node) = 0;
    virtual void visit(IntLitASTnode& node) = 0;
};

class ASTnode {
     public :
     virtual ~ASTnode()
     {
     }
     
     virtual void accept(ASTvisitor& V) = 0;

};

class BinaryASTnode : public ASTnode {
     std::string bin_operator;  

// lhs and rhs can be of any type. 
// So we need to use BaseAST
     ASTnode  *left;
     ASTnode *right;  

     public:

// Constructor to initialize binary operator, 
// lhs and rhs of the binary expression.
     BinaryASTnode (std::string op, ASTnode* _left, ASTnode* _right ) :
     bin_operator(op), left(_left), right(_right) {}  

    ASTnode* getLeft() {
        return left;
    }

    ASTnode* getRight() {
        return right;
    }

    std::string getBin_operator() {
        return bin_operator;
    }
     virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }

};

class TernaryASTnode : public ASTnode {

     ASTnode  *first;
     ASTnode *second;
     ASTnode *third;  

     public:

     TernaryASTnode (ASTnode *first, ASTnode *second, ASTnode *third ) :
     first(first), second(second), third(third) {}  

    ASTnode* getFirst()
    {
        return first;
    }

    ASTnode* getSecond()
    {
        return second;
    }

    ASTnode* getThird()
    {
        return third;
    }

     virtual void accept(ASTvisitor& v) 
    {
      v.visit(*this);
    }
};

class IntLitASTnode: public ASTnode {

	int intlit;

	public:

	IntLitASTnode(int intlit): 
	intlit(intlit){}

    int getIntLit()
    {
        return intlit;
    }

     virtual void accept(ASTvisitor& v) 
    {
      v.visit(*this);
    }

};

class ASTContext {
public:
    ASTnode *root;

    ~ASTContext()
    {
	    clearAST();
    }

    /// free all saved expression trees
    void	clearAST()
    {
        delete root;
    }
};
