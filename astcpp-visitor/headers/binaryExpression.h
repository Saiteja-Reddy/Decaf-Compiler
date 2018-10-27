#include <string>
#include "expression.h"

using namespace std;

class binaryExpression : public Expression {
private:
    /* left hand side */
    class Expression *lhs;

    /* right hand side */
    class Expression *rhs;

    /* operator in between */
    string opr;
public:
    binaryExpression(class Expression *, string, class Expression *);

};
