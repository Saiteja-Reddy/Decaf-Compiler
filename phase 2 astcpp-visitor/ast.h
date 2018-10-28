class ProgramASTnode;
class FieldDec;
class FieldDecList;
class Variable;
class Variables;
class integerLit;
class Lit;
class Expr;

using namespace std;


class ASTvisitor {
  public:
    virtual void visit(ProgramASTnode& node) = 0;
    virtual void visit(FieldDec& node) = 0;
    virtual void visit(FieldDecList& node) = 0;
    virtual void visit(Variable& node) = 0;
    virtual void visit(Variables& node) = 0;
    virtual void visit(integerLit& node) = 0;
    virtual void visit(Lit& node) = 0;
    virtual void visit(Expr& node) = 0;
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

    class FieldDecList *fields;

    public:

    ProgramASTnode(string name) : name(name) {}
    
    ProgramASTnode(string name, class FieldDecList *fields ) : name(name), fields(fields) {}

    string getProgramName() {
        return name;
    }

    class FieldDecList * getFields() {
        return fields;
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

    Variable(string name, unsigned int length) : name(name), length(length), declType(::Array) {}
    Variable(string name) : name(name), declType(::Normal) {}

    bool isArray() { return (declType == ::Array); }

    string getName() { return name; };

    unsigned int getLength() { return length; }

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};

class Variables: public ASTnode {
    
    vector<class Variable *> vars_list;

    public:
    Variables() {};

    void push_back(class Variable *var)
    {
        vars_list.push_back(var);
    }

    vector<class Variable *> getVarsList()
    {
        return vars_list;
    }

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};


class FieldDec: public ASTnode {
    string datatype;

    vector<class Variable *> var_list;

    public:

    FieldDec(string dtype, class Variables *variables) : datatype(dtype), var_list(variables->getVarsList()) {}

    string getType()
    {
        return datatype;
    }

    vector<class Variable *> getVarsList()
    {
        return var_list;
    }

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};


class FieldDecList: public ASTnode {
    
    vector<class FieldDec *> declaration_list;

    public:

    FieldDecList() {};

    vector<class FieldDec *> getList()
    {
        return declaration_list;
    }

    void push_back(class FieldDec *fieldDec)
    {
        declaration_list.push_back(fieldDec);
    }

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};


enum exprType {
    binary = 1, location = 2, literal = 3, enclExpr = 4, unExpr = 5
};

class Expr: public ASTnode {
    
    exprType etype;

    public:

    Expr() {};

    exprType getEtype() { return etype; }

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};


enum literalType {
    Int = 1, Bool = 2, Char = 3, String = 4
};

class Lit: public Expr {
    
    literalType ltype;

    public:

    Lit(literalType type) : ltype(type) {};

    virtual int getValue() {return -1;};

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};


class integerLit: public Lit {
    
    int value;

    public:

    integerLit(int value) : value(value), Lit(::Int) {};

    virtual int getValue() {return value;};

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
