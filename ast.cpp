#include "ast.h"

using namespace std;


map <string, string> check_in_scope(string name, map <string, string> mymap)
{
    map <string, string> output;
    output["name"] = "";
    output["type"] = "";
    output["arr"] = "no";

    if(mymap.count(name))
    {
        output["name"] = name;
        output["type"] = mymap[name];
    }
    else
    {
        if(global_map.count(name))
        {
            output["name"] = name;
            output["type"] = global_map[name];
        }
    }

    return output;
}

void Block::init_mymap(class var_decs * decs)
{
    for(auto& i:decs->mymap)
	{
		mymap[i.first] = i.second;
		scope_map[i.first] = i.second;
	}    
}

void Block::add_to_mymap(map <string, string> in_map)
{
    for(auto& i:in_map)
	{
		mymap[i.first] = i.second;
		scope_map[i.first] = i.second;
	}     
}

