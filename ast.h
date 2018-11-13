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
class UnExpr;
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
class Location;
class Assign;


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
    virtual void visit(UnExpr& node) = 0;
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
    virtual void visit(Location& node) = 0; 
    virtual void visit(Assign& node) = 0; 
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
    int length;

    public:

    Variable(string name1, int length1) 
    {
        name =name1;
        length = length1;
        declType = ::Array;
        if(length1 <= 0)
            cout << "Error" << ": Array Size during declaration must be greater than zero.\n";

    }
    Variable(string name) : name(name), declType(::Normal) {}

    bool isArray() { return (declType == ::Array); }

    string getName() { return name; };

    int getLength() { return length; }

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
    FieldDec() {
        datatype = "Comment";   
    }

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

enum exprData {
    boolean = 1, integer = 2, mixed = 3, def = 4
};

enum literalType {
    Bool = 1, Int = 2, Char = 3, String = 4
};

class Expr: public ASTnode {
    
    exprType etype;
    exprData edata;

    public:

    Expr() { edata = ::def;};
    Expr(exprData val) { edata = val;};

    exprType getEtype() { return etype; }
    exprData getEdata() { return edata; }
    
    void setEdata(int a)
    { 
        switch(a)
        {
            case 1: edata = ::boolean;
                    break;
            case 2: edata = ::integer;
                      break;
            case 3: edata = ::mixed;
                      break;
            case 4: edata = ::def;
        }
    }

    void updateEdata(exprData val)
    {
        if(edata == ::def)
        {
            edata = val;
        }
        else if(val == ::boolean || val == ::integer)
        {
            if(edata != val)
                edata = ::mixed;
        }
    }

    void updateEdata(int val)
    {
        if(val == 1)
        {
            if(edata == 4)
            {
                edata = ::boolean;
            }
            else
            {
                if(2 == edata)
                    edata = ::mixed;
            }
        } 
        else if(val == 2)
        {
            if(edata == 4)
            {
                edata = ::integer;
            }
            else
            {
                if(1 == edata)
                    edata = ::mixed;
            }
        }         
        else
            edata = ::mixed;
    }

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

    BinExpr(class Expr *lhss, class Expr *rhss, string ops)
    {
        lhs = lhss;
        rhs = rhss;
        op = ops;
        check_types();
    }

    void check_types()
    {
        int a = lhs->getEdata();
        int b = rhs->getEdata();

        if(find_init())
        {
            if(a != ::integer || b!= ::integer)
            {
                cout << "Error" << ": Both sides of " << op << " must be int.\n";
            }
        }
        else if(find_strs())
        {
            if(!((a == ::integer && b== ::integer) || (a == ::boolean && b== ::boolean)))
            {
                cout << "Error: Both sides of " << op << " must be int or boolean.\n"; 
            }
        }

    }

    int find_init()
    {
        string init[] = {"+", "-", "*", "/", "%", ">", "<", "<=", ">="};
        for(int i=0; i<9; i++)
        {
            if(op == init[i])
                return 1;
        }
        return 0;
    }

    int find_strs()
    {
        string strs[] = { "==", "!="};
        for(int i=0; i<2; i++)
        {
            if(op == strs[i])
                return 1;
        }
        return 0;        
    }

    class Expr * getLhs() { return lhs; }
    class Expr * getRhs() { return rhs; }
    string getOp() { return op; }

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};

class UnExpr: public Expr {
    class Expr *exp;
    string op;
    public:

    UnExpr(string ops, class Expr *exps)
    {
        exp = exps;
        op = ops;
        check_types();
    }

    void check_types()
    {
        int a = exp->getEdata();
        if(a != ::boolean)
        {
            cout << "Error: Unary Operator must have only boolean type. \n";
        }
    }


    class Expr * getExp() { return exp; }
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


class Lit: public Expr {
    
    literalType ltype;

    public:

    Lit(literalType type) : ltype(type) {};

    virtual int getValue() {return -1;};
    
    int getLitType() {return ltype;};

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
    int else_pre;

    public:

    ifElseState(class Expr* conds, class Block* if_blocks, class Block* else_blocks)
    {
        cond = conds;
        checkIfCond();
        if_block = if_blocks;
        else_block= else_blocks;
        else_pre = 1; 
    }
    ifElseState(class Expr* conds, class Block* if_blocks)
    {
        cond = conds;
        checkIfCond();
        if_block = if_blocks;
        else_pre= 0;
    }

    class Expr* getCond() { return cond; }
    class Block* getIf() { return if_block; }
    class Block* getElse() { return else_block; }
    int getElsePre() { return else_pre; }

    void checkIfCond()
    {
        // cout << "in if cond check" << endl;
        // cout << cond->getEdata() << " type " << endl;
    }

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

    forState(string var1,class Expr * init1,class Expr * end_cond1,class Block* body1)
    {
        var = var1;
        init = init1;
        end_cond = end_cond1;
        body= body1;
        check_for();
    }

    void check_for()
    {
        int a = init->getEdata();
        int b = end_cond->getEdata();

        if(a != ::integer || b!= ::integer)
        {
            cout << "Error" << ":  initial and the ending EXPRS of FOR must have type int.\n";
        }
    }


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

class Assign: public Statement {

    class Location *loc;
    class Expr * exp;
    string op;

    public:
    
    Assign(class Location *loc1,string op1, class Expr * exp1)
    {
     loc = loc1;
     op = op1;
     exp = exp1;
    }

    class Expr* getRet() { return exp; }
    class Location* getLoc() {return loc;}
    string getOp(){ return op; }

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};

enum locationType {
    array = 1, variable = 2
};

class Location: public Expr {

    string var;
    locationType location_type;
    class Expr *array_index;

    public:
    
    Location(string vars)
    {
            var = vars;
            location_type = ::variable;           
    };

    Location(string vars, class Expr *array_indexs)
    {
            var = vars;
            location_type = ::array; 
            array_index = array_indexs;
            check_array_index();
    }

    void check_array_index()
    {
        int a = array_index->getEdata();
        if(a != ::integer)
        {
                cout << "Error" << ": Array Index must be of type int.\n";
        }
    }

    string getName() { return var; }

    bool isArray() { return location_type == ::array;}

    class Expr* getIndex() { return array_index;}

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

