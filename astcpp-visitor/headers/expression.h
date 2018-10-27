#include "ast.h"
#include <string>

enum exprType {
    binary = 1, location = 2, literal = 3, enclExpr = 4, unExpr = 5
};

class Expression : public ASTnode {
protected:
    exprType etype; /* Binary or unary or literal or location */
public:
    Expression() = default;

    exprType getEtype() { return etype; }

};
