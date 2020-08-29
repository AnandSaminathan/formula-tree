cmake_minimum_required(VERSION 3.7 FATAL_ERROR)

project(formula-tree)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wdeprecated -Wno-attributes" )

add_definitions(-DANTLR4CPP_SHARED)

set(ANTLR4_WITH_STATIC_CRT OFF)
set(ANTLR_EXECUTABLE ${PROJECT_SOURCE_DIR}/thirdparty/antlr/antlr-4.8-complete.jar)

include(ExternalAntlr4Cpp)
include(GNUInstallDirs)

include_directories(${ANTLR4_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(ANTLR REQUIRED)

antlr_target(GrammarLexer ${PROJECT_SOURCE_DIR}/src/FormulaLexer.g4 LEXER)
antlr_target(GrammarParser ${PROJECT_SOURCE_DIR}/src/FormulaParser.g4 
             PARSER
	           VISITOR
             DEPENDS_ANTLR GrammarLexer
             COMPILE_FLAGS -lib ${ANTLR_GrammarLexer_OUTPUT_DIR})

include_directories(${ANTLR_GrammarLexer_OUTPUT_DIR})
include_directories(${ANTLR_GrammarParser_OUTPUT_DIR})


file(GLOB SOURCE ${PROJECT_SOURCE_DIR}/src/*.h 
		 ${PROJECT_SOURCE_DIR}/src/*.cpp
    )

add_library(formula-tree SHARED 
            ${PROJECT_SOURCE_DIR}/src/formula-tree.cpp
            ${PROJECT_SOURCE_DIR}/src/FormulaVisitor.h
            ${PROJECT_SOURCE_DIR}/src/FormulaVisitor.cpp
            ${ANTLR_GrammarLexer_CXX_OUTPUTS}
            ${ANTLR_GrammarParser_CXX_OUTPUTS})

target_include_directories(formula-tree PRIVATE ${ANTLR4_INCLUDE_DIRS}
                          ${PROJECT_SOURCE_DIR}/include
                          ${ANTLR_GrammarLexer_OUTPUT_DIR}
                          ${ANTLR_GrammarParser_OUTPUT_DIR})
target_link_libraries(formula-tree antlr4_shared)

if(WITH_TEST)
  enable_testing()
  add_subdirectory(tests)
endif(WITH_TEST)

set(POST_BUILD_INCLUDE_DIRECTORY $<TARGET_FILE_DIR:formula-tree>/include)
set(POST_BUILD_BIN_DIRECTORY $<TARGET_FILE_DIR:formula-tree>/bin)

add_custom_command(TARGET formula-tree POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  "${PROJECT_SOURCE_DIR}/include"
  ${POST_BUILD_INCLUDE_DIRECTORY})

add_custom_command(TARGET formula-tree POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  "${ANTLR4_ROOT}/runtime/Cpp/dist"
  ${POST_BUILD_BIN_DIRECTORY})

add_custom_command(TARGET formula-tree POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  $<TARGET_FILE:formula-tree>
  ${POST_BUILD_BIN_DIRECTORY})

add_custom_command(TARGET formula-tree POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E tar "cfv" "formulatree-source.zip" --format=zip
  ${POST_BUILD_INCLUDE_DIRECTORY}
  ${POST_BUILD_BIN_DIRECTORY})
