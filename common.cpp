// map <string, int> global_map  = map <string, int>();
#include <string>
#include <iostream>
#include <map>
#include <vector>

#include <llvm/IR/Verifier.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

using namespace std;

string test_var = "Hello \n";

map <string, string> global_map = map <string, string>();

map <string, vector<string> > methods_decs_map = map <string, vector<string> >();

map <string, string > methods_decs_return = map <string, string >();
