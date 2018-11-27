# _DECAF Compiler_
_Sai Teja Reddy Moolamalla_

## Make instructions:

* From the directory where the Makefile is present, run:
	`make`
* Using the Compiler:
	`./decaf_compiler <input_file>`
* Running the generated LLVM IR:
	`lli output_final.decaf`
* To delete all the object files:
	`make clean`

## File Breakdown

```
.
|-- Decafspec.pdf - The Specifications of the _decaf_ compiler
|-- Makefile - The Makefile to build the source code
|-- PostfixVisitor.h - Visitor Pattern for traversing the built AST
|-- ast.cpp - AST code file
|-- ast.h - AST header file and class declarations
|-- common.cpp - Common Static Variables for AST Building
|-- common.h - Header File for common.cpp
|-- decaf_lib.c - Personalised library made by user for DECAF compiler to use
|-- decaf_linker.sh - Linker for decaf scripts
|-- parser.ypp - Parser File
|-- scanner.l - Scanner File
|-- test-programs - Few test-programs
```

## Description

**_Implementation Details:_** The `scanner.l` code is utilized in scanning the tokens from the input file, the stream of the generated tokens is given as input to the parser. The `parser.ypp` file generates an AST representation of the given input file. We then do a traversal of the constructed AST using `PostfixVisitor.h` to check for few semantic errors in the constructed AST. Then, using the `generate_code` function in each AST node we get a dump of the LLVM IR from the AST, into the `output_final.decaf` file. `decaf_lib.c` is the file to add custom functions by the user in C-Language for the decaf compiler to support. These library functions are linked to tthe generated LLVM dump using `decaf_linker.sh`.

**_Things to Complete:_**

- Exhaustive Testing for Errors
