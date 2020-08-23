# Formula Tree

A C++ library to parse a formula represented as a string and convert it into a tree. The library exposes various methods as an API to perform a multitude of operations on this tree such as conversion to Negation Normal Form (NNF). In addition to these methods, the class contains public traversal methods which can thus allow custom operations.

The formula can be of type
- Linear Temporal Logic (LTL)
- Propositional Logic (PL)
- Pseudo Boolean (PB)

## Dependencies

- ANTLR 
- Catch2 

## Usage

Create a file `ExternalFormulaTree.cmake` in the required project with contents as
```cmake
cmake_minimum_required(VERSION 3.7)

include(ExternalProject)

ExternalProject_Add(
        git_formulatree
        PREFIX ${CMAKE_BINARY_DIR}/formulatree
        URL https://github.com/AnandSaminathan/formula-tree/releases/download/v1.0/formulatree-source.zip
        #TIMEOUT 10
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        UPDATE_COMMAND ""
        INSTALL_COMMAND ""
        LOG_DOWNLOAD ON
)
ExternalProject_Get_Property(git_formulatree source_dir)

add_library(formula-tree INTERFACE)
target_include_directories(formula-tree INTERFACE ${source_dir}/include)
target_link_libraries(formula-tree INTERFACE ${source_dir}/bin/libformula-tree.so)
target_link_libraries(formula-tree INTERFACE ${source_dir}/bin/libantlr4-runtime.so)
```

In the main `CMakeLists.txt`, link the required object with
```
include(ExternalFormulaTree)

...
target_link_libraries(required-target formula-tree)
...
```