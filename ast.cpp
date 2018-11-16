#include "ast.h"

using namespace std;

void Block::init_mymap(class var_decs * decs)
{
    mymap = decs->mymap;
}
