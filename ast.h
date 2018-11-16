#include <bits/stdc++.h>

using namespace std;

#include "common.h"

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


class ASTvisitor {
  public:
    virtual void visit(ProgramASTnode& node) = 0;
    virtual void visit(FieldDec& gnode) = 0;
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
    ProgramASTnode(string name1, class FieldDecList *fields1, class meth_decs *methods1)
    {
        name = name1;
        fields = fields1;
        methods = methods1;
        checkMain();
    }

    void checkMain()
    {
        if(methods_decs_map.count("main"))
        {
            if(methods_decs_map["main"].size() > 0)
            {
                cout << "ERROR: There must be a main method with no parameters\n"; 
            }
        }
        else
        {
            cout << "ERROR: There must be a main method with no parameters\n";
        }

    }

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
    public:
   
    string datatype;

    vector<class Variable *> var_list;


    FieldDec(string dtype, class Variables *variables) : datatype(dtype), var_list(variables->getVarsList()) {}
    FieldDec() {
        datatype = "Comment";   
    }

    string getType()
    {
        return datatype;
    }

    vector <string> getVarNames()
    {
        vector <string> vars;

        for(auto& i: var_list)
        {
            vars.push_back(i->getName());
        }

        return vars;
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
    map <string, string> mymap;

    public:

    FieldDecList() {
        // cout << " Field Dec Lis\n";
    };

    void getMap()
    {
        // cout << test_var << endl;
        for(auto& i: declaration_list)
        {
            vector <string> now_list = i->getVarNames();
            for(auto& j: now_list)
            {
                string type = i->datatype;
                // cout << i->getType() << " - " << j << endl;
                if(mymap.count(j) || methods_decs_map.count(j))
                    cout << "ERROR : Already defined the variable '" << j << "'" << endl; 
                mymap[j] = type;
                global_map[j] = type;

                // cout << "added global map - " << j << endl;
            }
        }
    }

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
        getMap();
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
    
    public:
    
    exprType etype;
    exprData edata;
    map <string, int> expr_map;
    int check_meth_call;

    Expr() { edata = ::def; check_meth_call = 0;};
    Expr(exprData val) { edata = val; check_meth_call = 0;};

    exprType getEtype() { return etype; }
    exprData getEdata() { return edata; }
    
    void setEdata(exprData now) 
    {
        edata = now;
    }

    void add_to_expr_map(string name, int type)
    {
        expr_map[name] = type;
    }

    void print_expr_map()
    {
        for(auto& i: expr_map)
        {
            cout << i.first <<  "  ---- " << i.second << endl;
        }
    }

    string getExpData()
    {
        switch(edata)
        {
            case ::boolean: return "boolean" ;
            case ::integer: return "int" ;
            case ::mixed: return "mixed" ;
            case ::def : return "def";
        }
    }
    
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

    virtual void check_accept(ASTvisitor& v)
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
        map <string, int> now_map = lhss->expr_map;
        for(auto& i: now_map)
        {
            add_to_expr_map(i.first, i.second);
        }
        now_map = rhss->expr_map;
        for(auto& i: now_map)
        {
            add_to_expr_map(i.first, i.second);
        }

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

        map <string, int> now_map = exps->expr_map;
        for(auto& i: now_map)
        {
            add_to_expr_map(i.first, i.second);
        }        
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

    EncExpr(class Expr *expr1)
    {
        expr = expr1;
        map <string, int> now_map = expr1->expr_map;
        for(auto& i: now_map)
        {
            add_to_expr_map(i.first, i.second);
        }
    }

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
    public:

    stmtType stype;
    int check_control;
    map <string, string> scope_map;
    map <string, int> var_map;

    Statement()
    {
        stype = ::NonReturn;
        check_control = 0;
    }

    Statement(int check_control1)
    {
        stype = ::NonReturn;
        check_control = check_control1;
    }

    void set_scope_map(map <string, string> in_map)
    {
        scope_map = in_map;
    }

    void print_scope_map()
    {
        cout << "\n\nState Map\n";
        for(auto& i: scope_map)
        {
            cout << i.first <<  "  ---- " << i.second << endl;
        }
        cout << "State Map done\n\n";
    }

    void add_scope_map(string name, string type)
    {
        scope_map[name] = type;
    }

    void set_var_map(map <string, int> in_map)
    {
        var_map = in_map;
    }

    void add_to_var_map(string name, int type)
    {
        var_map[name] = type;
    }
    
    virtual void setReturn() {stype = ::Return;};

    virtual bool hasReturn() {return stype == ::Return;};

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};

class Statements: public ASTnode {
    
    public:

    vector<class Statement *> statements_list;
    int has_control;


    Statements() {
        has_control = 0;
    };

    vector<class Statement *> getList()
    {
        return statements_list;
    }


    void set_var_map(map <string, int> in_map)
    {
        for(auto& i: statements_list)
        {
            i->set_var_map(in_map);
        }
    }

    void set_scope_map(map <string, string> in_map)
    {
        for(auto& i: statements_list)
        {
            i->set_scope_map(in_map);
        }
    }    

    void push_back(class Statement *state)
    {
        if(state->check_control)
        {
            has_control = 1;
        }
        statements_list.push_back(state);
    }

    int get_has_control()
    {
        return has_control;
    }

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};


class Block: public Statement {
    public:
    
    class var_decs *declarations_list;

    class Statements *statements_list;

    map <string, string> mymap;


    Block() {
        statements_list = NULL;
    };

    void init_mymap(class var_decs * decs); // in ast.cpp
    void add_to_mymap(map <string, string> in_map);

    void print_mymap()
    {
        cout << "\n\nBlock Map\n";
        for(auto& i: mymap)
        {
            cout << i.first <<  "  ---- " << i.second << endl;
        }
        cout << "Block Map done\n\n";
    }

    Block(class var_decs * decs, class Statements *states)
    {
        declarations_list = decs;
        statements_list = states;
    }

    // virtual boolean hasReturn() {return stype == ::NonReturn;};

    class var_decs * get_var_decs()
    {
        return declarations_list;
    }

    class Statements * get_states()
    {
        return statements_list;
    }   

    int check_control()
    {
        if(statements_list != NULL)
        {
            // cout << "Here \n";
            return statements_list->has_control;
        }
        else
            return 0;
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
    public:
    
    string type;
    vector<string> var_list;

    var_dec(string type1, class string_list* str_list)
    {
        type = type1;
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

    vector <string> getVarNames()
    {
        vector <string> vars;

        for(auto& i: var_list)
        {
            vars.push_back(i);
        }

        return vars;
    }


    virtual string getType() {return type;};
    
    virtual vector<string> getList() {return var_list;};
    
    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};

class var_decs: public ASTnode {
    
    public:

    vector<class var_dec *> var_decs_list;
    map <string, string> mymap;

    var_decs() {};

    vector<class var_dec *> getList()
    {
        return var_decs_list;
    }

    void push_back(class var_dec *arg)
    {
        var_decs_list.push_back(arg);
    }

    void getMap()
    {
        for(auto& i: var_decs_list)
        {
            string type = i->type;
            vector <string> now_list = i->getVarNames();
            for(auto& j: now_list)
            {
                // cout << i->getType() << " vardec - " << j << endl;
                if(global_map.count(j))
                    cout << "ERROR : Already defined the variable Globally - '" << j << "'" << endl; 
                if(mymap.count(j))
                    cout << "ERROR : Already defined the variable '" << j << "'" << endl; 
                mymap[j] = type;
            }
        }

    }   

    virtual void accept(ASTvisitor& v)
    {
      getMap();
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
    
    public:

    vector<class meth_arg *> meth_args_list;
    vector <string> arg_list_types;
    
    map <string, string> arg_list;


    meth_args() {};

    vector<class meth_arg *> getList()
    {
        return meth_args_list;
    }

    void push_back(class meth_arg *arg)
    {
        arg_list[arg->getName()] = arg->getType();
        arg_list_types.push_back(arg->getType());
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

    meth_dec(string return_type1, string name1, class meth_args *args1, class Block* blc )
    {
     return_type = return_type1;
     name = name1;
     // cout << " MEth decHere" << name << " - " << global_map.count(name) << "\n";
     if(methods_decs_map.count(name) || global_map.count(name))
     {
        cout << "ERROR: Method/Variable " << name << " is redefined.\n";
     }

     methods_decs_map[name] = args1->arg_list_types;
     methods_decs_return[name] = return_type;

     arg_list = args1;
     if(blc->check_control())
        cout << "ERROR: BREAK/CONTINUE in method declaration is invalid" << endl;     
     body = blc;
    }

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

class Parameters: public ASTnode {

    public:
    
    vector<class Expr *> params;
    vector<string> data_types;
    map <string, int> expr_map;

    Parameters() {};

    void push_back(class Expr *E)
    {
        data_types.push_back(E->getExpData());
        
        map <string, int> now_map = E->expr_map;
        for(auto& i: now_map)
        {
            expr_map[i.first] = i.second;
        }

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


class meth_call: public Statement, public Expr {
    
    string name;
    class Parameters* params;

    public:
    
    meth_call(){check_meth_call = 1;};
    meth_call(string name1,class Parameters* params1 )
    {
        check_meth_call = 1; 
        name = name1;
        params = params1;
        if(methods_decs_map.count(name))
        {
            vector <string> meth_data_types = methods_decs_map[name];
            vector <string> data_types = params1->data_types;
            if(meth_data_types.size() != data_types.size())
            {
                cout << "ERROR : Method " << name << " needs " <<  meth_data_types.size() << " arguments\n";
            }
            else
            {
                for (int i = 0; i < data_types.size(); ++i)
                {
                    // cout << meth_data_types[i] << "  fasasfad " << data_types[i] << endl;
                   if(meth_data_types[i] != data_types[i])
                   {
                     cout << "ERROR : Usage of Method " << name << "'s Parameters is wrong in method call.\n";
                     break;
                   }
                }
            }

            if(methods_decs_return[name] == "void")
                setEdata(::mixed);
            else if(methods_decs_return[name] == "int")
                setEdata(::integer);
            else if(methods_decs_return[name] == "boolean")
            {
                cout << "HHSGAFASADADAD\n";
                setEdata(::boolean);            
            }


            map <string, int> now_map = params1->expr_map;
            for(auto& i: now_map)
            {
                add_to_expr_map(i.first, i.second);
            }

            // print_expr_map();  

        }
        else
            cout << "ERROR: Method " << name << " is not defined before use.\n";
    }

    string getName() {  return name;    }

    class Parameters* getParams() { return params;}

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }

    virtual void check_accept(ASTvisitor& v)
    {
      if(methods_decs_return[name] == "void")
      {
        cout << "\nERROR: Method Call " << name << " must return a value for expr.\n";
      }
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


class breakState: public Statement {

    public:

    breakState(): Statement(1) {};

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};

class continueState: public Statement {

    public:

    continueState(): Statement(1) {};

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
        if(if_blocks->check_control())
            cout << "ERROR: BREAK/CONTINUE in if block invalid" << endl; 
        if(else_blocks->check_control())
            cout << "ERROR: BREAK/CONTINUE in else block invalid" << endl;                     

        if_block = if_blocks;
        else_block= else_blocks;
        else_pre = 1; 
    }
    ifElseState(class Expr* conds, class Block* if_blocks)
    {
        cond = conds;
        if(if_blocks->check_control())
            cout << "ERROR: BREAK/CONTINUE in if block invalid" << endl;        

        if_block = if_blocks;
        else_block = NULL;
        else_pre= 0;
    }

    class Expr* getCond() { return cond; }
    class Block* getIf() { return if_block; }
    class Block* getElse() { return else_block; }
    int getElsePre() { return else_pre; }

    void checkIfCond()
    {
        // cout << "Here incond\n";
        // if(if_block->check_control())
            // cout << "ERROR: in if cond check" << endl;
        // cout << cond->getEdata() << " type " << endl;
    }

    virtual void accept(ASTvisitor& v)
    {
      v.visit(*this);
    }
};

class forState: public Statement {
    public:

    string var;
    class Expr * init;
    class Expr * end_cond;
    class Block* body;

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
            add_to_expr_map(vars, 0);
    };

    Location(string vars, class Expr *array_indexs)
    {
            var = vars;
            location_type = ::array; 
            array_index = array_indexs;
            check_array_index();
            add_to_expr_map(vars, 1);
            map <string, int> now_map = array_indexs->expr_map;
            for(auto& i: now_map)
            {
                add_to_expr_map(i.first, i.second);
            }
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
