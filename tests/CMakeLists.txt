add_executable(test-sample-formula test-sample-formula.cpp
               ${ANTLR_GrammarLexer_CXX_OUTPUTS}
               ${ANTLR_GrammarParser_CXX_OUTPUTS}
               ${SOURCE})
add_executable(test-formula-tree test-formula-tree.cpp
               ${ANTLR_GrammarLexer_CXX_OUTPUTS}
               ${ANTLR_GrammarParser_CXX_OUTPUTS}
               ${SOURCE})
add_executable(test-leaf-configs test-leaf-configs.cpp
               ${ANTLR_GrammarLexer_CXX_OUTPUTS}
               ${ANTLR_GrammarParser_CXX_OUTPUTS}
               ${SOURCE})
add_executable(test-leaf-configs-2 test-leaf-configs-2.cpp
               ${ANTLR_GrammarLexer_CXX_OUTPUTS}
               ${ANTLR_GrammarParser_CXX_OUTPUTS}
               ${SOURCE})
add_executable(test-nnf test-nnf.cpp
               ${ANTLR_GrammarLexer_CXX_OUTPUTS}
               ${ANTLR_GrammarParser_CXX_OUTPUTS}
               ${SOURCE})
add_executable(test-nnf-2 test-nnf-2.cpp
               ${ANTLR_GrammarLexer_CXX_OUTPUTS}
               ${ANTLR_GrammarParser_CXX_OUTPUTS}
               ${SOURCE})
add_executable(test-nnf-3 test-nnf-3.cpp
               ${ANTLR_GrammarLexer_CXX_OUTPUTS}
               ${ANTLR_GrammarParser_CXX_OUTPUTS}
               ${SOURCE})
add_executable(test-propositional-formula test-propositional-formula.cpp
               ${ANTLR_GrammarLexer_CXX_OUTPUTS}
               ${ANTLR_GrammarParser_CXX_OUTPUTS}
               ${SOURCE})
add_executable(test-pseudo-boolean-formula test-pseudo-boolean-formula.cpp
               ${ANTLR_GrammarLexer_CXX_OUTPUTS}
               ${ANTLR_GrammarParser_CXX_OUTPUTS}
               ${SOURCE})
add_executable(test-substitute test-substitute.cpp
               ${ANTLR_GrammarLexer_CXX_OUTPUTS}
               ${ANTLR_GrammarParser_CXX_OUTPUTS}
               ${SOURCE})


target_link_libraries(test-sample-formula antlr4_static)
target_link_libraries(test-formula-tree antlr4_static)
target_link_libraries(test-leaf-configs antlr4_static)
target_link_libraries(test-leaf-configs-2 antlr4_static)
target_link_libraries(test-nnf antlr4_static)
target_link_libraries(test-nnf-2 antlr4_static)
target_link_libraries(test-nnf-3 antlr4_static)
target_link_libraries(test-pseudo-boolean-formula antlr4_static)
target_link_libraries(test-propositional-formula antlr4_static)
target_link_libraries(test-substitute antlr4_static)
