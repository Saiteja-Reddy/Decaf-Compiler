class ProgramASTnode;
class FieldDec;
class FieldDecList;
class Variable;
class Variables;
class integerLit;
class boolLit;
class charLit;
class stringLit;
class Lit;
class Expr;
class Statement;
class Statements;
class Block;
class meth_arg;
class meth_args;
class meth_dec;
class meth_decs;
class var_dec;
class var_decs;
class string_list;
class meth_call;
class BinExpr;
class EncExpr;
class Parameters;
class calloutArgs;
class calloutArg;
class callout_call;
class breakState;
class continueState;
class ifElseState;
class forState;
class returnState;


using namespace std;


class ASTvisitor {
  public:
    virtual void visit(ProgramASTnode& node) = 0;
    virtual void visit(FieldDec& node) = 0;
    virtual void visit(FieldDecList& node) = 0;
    virtual void visit(Variable& node) = 0;
    virtual void visit(Variables& node) = 0;
    virtual void visit(integerLit& node) = 0;
    virtual void visit(boolLit& node) = 0;
    virtual void visit(charLit& node) = 0;
    virtual void visit(Lit& node) = 0;
    virtual void visit(Expr& node) = 0;
    virtual void visit(Block& node) = 0;
    virtual void visit(Statement& node) = 0;
    virtual void visit(Statements& node) = 0;
    virtual void visit(meth_arg& node) = 0;
    virtual void visit(meth_args& node) = 0;
    virtual void visit(meth_dec& node) = 0;
    virtual void visit(meth_decs& node) = 0;
    virtual void visit(var_dec& node) = 0;
    virtual void visit(var_decs& node) = 0;
    virtual void visit(meth_call& node) = 0;
    virtual void visit(BinExpr& node) = 0;
    virtual void visit(EncExpr& node) = 0;
    virtual void visit(Parameters& node) = 0;
    virtual void visit(stringLit& node) = 0;
    virtual void visit(calloutArgs& node) = 0;
    virtual void visit(calloutArg& node) = 0;
    virtual void visit(callout_call& node) = 0; 
    virtual void visit(breakState& node) = 0; 
    virtual void visit(continueState& node) = 0; 
    virtual void visit(ifElseState& node) = 0; 
    virtual void visit(forState& node) = 0; 
    virtual void visit(returnState& node) = 0; 
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

    class meth_decs *methods;

    public:

    ProgramASTnode(string name) : name(name) {}
    ProgramASTnode(string name, class FieldDecList *fields, class meth_decs *methods) : name(name), fields(fields), methods(methods) {}

    string getProgramName() {
        return name;
    }

    class FieldDecList * getFields() {
        return fields;
    }

    class meth_decs * getMeths() {
        return methods;
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

class BinExpr: public Expr {
    class Expr *lhs;
    class Expr *rhs;
    string op;
    public:

    BinExpr(class Expr *lhs, class Expr *rhs, string op): lhs(lhs), rhs(rhs), op(op)  {};

    class Expr * getLhs() { return lhs; }
    class Expr * getRhs() { return rhs; }
    string getOp() { return op; }

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};

class EncExpr: public Expr {
    class Expr *expr;
    public:

    EncExpr(class Expr *expr): expr(expr) {};

    class Expr * getexpr() { return expr; }

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

class boolLit: public Lit {
    
    string value;

    public:

    boolLit(string value) : value(value), Lit(::Bool)  {};

    virtual string getVal() {return value;};

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};

class charLit: public Lit {
    
    char value;

    public:

    charLit(string value) : value(value[1]), Lit(::Char) {};

    virtual char getVal() {return value;};

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};

class stringLit: public Lit {
    
    string value;

    public:

    stringLit(string value) : value(value), Lit(::String) {};

    virtual string getVal() {return value;};

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};

enum stmtType {
    Return = 1, NonReturn = 2
};

class Statement: public ASTnode {
    
    stmtType stype;

    public:

    Statement() : stype(::NonReturn) {};
    
    virtual void setReturn() {stype = ::Return;};

    virtual bool hasReturn() {return stype == ::Return;};

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};

class Statements: public ASTnode {
    
    vector<class Statement *> statements_list;

    public:

    Statements() {};

    vector<class Statement *> getList()
    {
        return statements_list;
    }

    void push_back(class Statement *state)
    {
        statements_list.push_back(state);
    }

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};


class Block: public Statement {
    
    class var_decs *declarations_list;

    class Statements *statements_list;

    public:

    Block() {};
    Block(class var_decs * decs, class Statements *states): declarations_list(decs), statements_list(states)  {};

    // virtual boolean hasReturn() {return stype == ::NonReturn;};

    class var_decs * get_var_decs()
    {
        return declarations_list;
    }

    class Statements * get_states()
    {
        return statements_list;
    }    

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};

class string_list {
    vector<string> list;

    public:

    string_list() {};

    void push_back(string arg)
    {
        list.push_back(arg);
    }    
    
    virtual vector<string> getList() {return list;};

};

class var_dec: public ASTnode {
    string type;
    vector<string> var_list;

    public:

    var_dec(string type, class string_list* str_list)
    {
        type = type;
        vector<string> list = str_list->getList();
        for (auto &i : list) 
        {
            var_list.push_back(i);
        }        
    };

    void push_back(string arg)
    {
        var_list.push_back(arg);
    }    

    virtual string getType() {return type;};
    
    virtual vector<string> getList() {return var_list;};
    
    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};

class var_decs: public ASTnode {
    
    vector<class var_dec *> var_decs_list;

    public:

    var_decs() {};

    vector<class var_dec *> getList()
    {
        return var_decs_list;
    }

    void push_back(class var_dec *arg)
    {
        var_decs_list.push_back(arg);
    }

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};



class meth_arg: public ASTnode {
    
    string type;
    string name;

    public:

    meth_arg(string type, string name) : type(type), name(name) {};

    virtual string getType() {return type;};
    
    virtual string getName() {return name;};

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};


class meth_args: public ASTnode {
    
    vector<class meth_arg *> meth_args_list;

    public:

    meth_args() {};

    vector<class meth_arg *> getList()
    {
        return meth_args_list;
    }

    void push_back(class meth_arg *arg)
    {
        meth_args_list.push_back(arg);
    }

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};

class meth_dec: public ASTnode {
    
    string return_type;
    string name;

    class meth_args *arg_list;

    class Block *body;

    public:

    meth_dec(string return_type, string name, class meth_args *args, class Block* blc ) : return_type(return_type), name(name),arg_list(args), body(blc) {};

    virtual string getType() {return return_type;};
    
    virtual string getName() {return name;};
    
    virtual class meth_args * getArgs() {return arg_list;};
    
    virtual class Block * getBlock() {return body;};

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};

class meth_decs: public ASTnode {
    
    vector<class meth_dec *> meth_decs_list;

    public:

    meth_decs() {};

    vector<class meth_dec *> getList()
    {
        return meth_decs_list;
    }

    void push_back(class meth_dec *arg)
    {
        meth_decs_list.push_back(arg);
    }

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};

class meth_call: public Statement, public Expr {
    
    string name;
    class Parameters* params;

    public:
    
    meth_call(){};
    meth_call(string name,class Parameters* params ) : name(name), params(params) {};

    string getName() {  return name;    }

    class Parameters* getParams() { return params;}

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};

class calloutArg: public ASTnode{

    class Expr *expr;

    public:
    
    calloutArg(class Expr *expr) : expr(expr) {};
    
    calloutArg(class stringLit *temp) {
        expr = temp;
    };

    class Expr * getExpr()
    {
        return expr;
    }

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }  
};

class calloutArgs: public ASTnode {
    vector<class calloutArg *> args;

    public:

    calloutArgs() {};

    void push_back(class calloutArg *E)
    {
        args.push_back(E);
    }

    vector<class calloutArg *> getArgs()
    {
        return args;
    }

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};

class callout_call: public meth_call{

    class calloutArgs *args;

    public:
    
    callout_call(class calloutArgs *args) : args(args) {};

    class calloutArgs *getArgs() {  return args;    }

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }  
};

class Parameters: public ASTnode {
    vector<class Expr *> params;

    public:

    Parameters() {};

    void push_back(class Expr *E)
    {
        params.push_back(E);
    }

    vector<class Expr *> getParams()
    {
        return params;
    }

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};


class breakState: public Statement {

    public:

    breakState() {};

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};

class continueState: public Statement {

    public:

    continueState() {};

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};


class ifElseState: public Statement {

    class Expr* cond;
    class Block* if_block;
    class Block* else_block;

    public:

    ifElseState(class Expr* cond, class Block* if_block, class Block* else_block): cond(cond), if_block(if_block), else_block(else_block) {};

    class Expr* getCond() { return cond; }
    class Block* getIf() { return if_block; }
    class Block* getElse() { return else_block; }

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};

class forState: public Statement {

    string var;
    class Expr * init;
    class Expr * end_cond;
    class Block* body;

    public:

    forState(string var,class Expr * init,class Expr * end_cond,class Block* body): var(var), init(init), end_cond(end_cond),body(body)  {};

    string getVar() { return var; }
    class Expr* getInit() { return init; }
    class Expr* getEnd() { return end_cond; }
    class Block* getBody() { return body; }


    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};

class returnState: public Statement {

    class Expr * ret;

    public:

    returnState(class Expr * returned)
    {
        Statement();
        setReturn();
        ret = returned;
    };
    
    returnState(): Statement() {};

    class Expr* getRet() { return ret; }

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
