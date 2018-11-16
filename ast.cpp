#include "ast.h"

using namespace std;

void Block::init_mymap(class var_decs * decs)
{
    for(auto& i:decs->mymap)
	{
		mymap[i.first] = i.second;
	}    
}

void Block::add_to_mymap(map <string, string> in_map)
{
    for(auto& i:in_map)
	{
		mymap[i.first] = i.second;
	}     
}
