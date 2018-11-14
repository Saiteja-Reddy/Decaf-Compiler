// $Id$

#include <iostream>
#include <fstream>

#include "driver.h"
// #include "ast.h"  
// ast.h included in PostFixVisitor.h
#include "PostFixVisitor.h"

using namespace std;

void Block::init_mymap(class var_decs * decs)
{
    mymap = decs->mymap;
}

int main(int argc, char *argv[])
{
    ASTContext ast;
    decaf::Driver driver(ast);
    PostFixVisitor pfv;
    
    std::string line;
    std::string code = "";

    fstream f("now.cpp", fstream::in );
  getline( f, code, '\0');
    f.close();
    
    // while( std::cout << "input: " &&
    //    std::getline(std::cin, line) &&
    //    !line.empty() )
    // {
    //     code += " ";
    //     code += line;
    // }

    std::cout << code << std::endl;

    bool result = driver.parse_string(code, "input");

    if (result)
    {
        if (ast.root != NULL ) {
            ProgramASTnode *pnode;

            pnode = dynamic_cast<ProgramASTnode *>(ast.root);

            if (pnode != NULL)
                pfv.visit(*pnode);

        }

        // ast.clearAST(); 
    }




    // while( std::cout << "input: " &&
	   // std::getline(std::cin, line) &&
	   // !line.empty() )
    // {
	    
	   //  bool result = driver.parse_string(line, "input");

	   //  if (result)
    // 	{
    //         if (ast.root != NULL ) {
    //             BinaryASTnode *bnode;
    //             TernaryASTnode *tnode;
    //             IntLitASTnode *inode;

    //             std::cout << "Postfix Form: " << std::endl; 

    //             bnode = dynamic_cast<BinaryASTnode *>(ast.root);
    //             if (bnode != NULL)
    //                 pfv.visit(*bnode);

    //             tnode = dynamic_cast<TernaryASTnode *>(ast.root);
    //             if (tnode != NULL)
    //                 pfv.visit(*tnode);

    //             inode = dynamic_cast<IntLitASTnode *>(ast.root);
    //             if (inode != NULL)
    //                 pfv.visit(*inode);
                
    //              std::cout <<  std::endl; 
 //            }
 //            ast.clearAST();
	//     }
	// }
}

