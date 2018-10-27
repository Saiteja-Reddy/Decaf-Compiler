cmake_minimum_required(VERSION 3.10)

project(decaf_compiler)

find_package(BISON)
find_package(FLEX)

set(CMAKE_FLEX_BISON_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/flex_bison_output)

# Create the directory for flex and bison outputs
file(MAKE_DIRECTORY ${CMAKE_FLEX_BISON_OUTPUT_DIRECTORY})

include_directories(headers)

include_directories(src)

BISON_TARGET(Parser src/calc.yy ${CMAKE_FLEX_BISON_OUTPUT_DIRECTORY}/calc.tab.cc)

FLEX_TARGET(Lexer src/calc.ll ${CMAKE_FLEX_BISON_OUTPUT_DIRECTORY}/lex.decaf.cc)

add_library(coreLibrary SHARED
			src/binaryExpression.cpp
			)


add_executable(decafCompiler
        ${FLEX_Lexer_OUTPUTS}
        ${BISON_Parser_OUTPUTS})

target_include_directories(decafCompiler PRIVATE
        ${CMAKE_FLEX_BISON_OUTPUT_DIRECTORY})

target_link_libraries(decafCompiler coreLibrary)


