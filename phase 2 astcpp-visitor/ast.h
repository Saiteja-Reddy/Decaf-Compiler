class BinaryASTnode;
class TernaryASTnode;
class IntLitASTnode;
class ProgramASTnode;
class FieldDecASTnode;
class Variable;


using namespace std;



class ASTvisitor {
  public:
    virtual void visit(BinaryASTnode& node) = 0;
    virtual void visit(TernaryASTnode& node) = 0;
    virtual void visit(IntLitASTnode& node) = 0;
    virtual void visit(ProgramASTnode& node) = 0;
};

class ASTnode {
     public :
     virtual ~ASTnode()
     {
     }

     virtual void accept(ASTvisitor& V) = 0;

};

class ProgramASTnode: public ASTnode {
    string name;

    public:

    ProgramASTnode(string name) : name(name) {}

    string getProgramName() {
        return name;
    }

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};

enum variableType {
    Array = 1, Normal = 2
};

class Variable: public ASTnode {
    
    variableType declType;
    string name;
    unsigned int length;

    public:

    Variable(string name, unsigned int length) : name(name), length(length), declType(variableType::Array) {}
    Variable(string name) : name(name), declType(variableType::Normal) {}

    bool isArray() { return (declType == variableType::Array); }

    string getName() { return name; };

    unsigned int getLength() { return length; }

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};


class FieldDecASTnode: public ASTnode {
    string datatype;

    vector<class Variable *> var_list;

    public:

    FieldDecASTnode(string dtype, class Variables *variables) : datatype(dtype), var_list(variables->getVarlist()) {}

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};


class BinaryASTnode : public ASTnode {
     std::string bin_operator;  

     ASTnode  *left;
     ASTnode *right;  

     public:

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
