clang -emit-llvm -c -g decaf_lib.c
# llvm-nm decaf_lib.bc
llvm-link output.txt decaf_lib.bc -o output_final.decaf
rm decaf_lib.bc
# rm output.txt
# lli output_final.bc
echo "Done linking decaf code"