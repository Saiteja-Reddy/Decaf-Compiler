/**
 * Implementation of \ref binaryExpression class */
#include <utility>

#include "binaryExpression.h"

/**
 * Constructor for binaryExpression class
 * @param lhs left hand side of the expression
 * @param opr operator present in the expression can be
 *            arithmetic operators like "+", "-", "*", "/", "%" or
 *            comparing operators like "<", ">", "<=", ">=", "==", "!="
 * @param rhs right hand side of the expression
 */
binaryExpression::binaryExpression(class Expression *lhs, string opr, class Expression *rhs) {
    this->lhs = lhs;
    this->rhs = rhs;
    this->opr = std::move(opr);
    this->etype = exprType::binary;
}
