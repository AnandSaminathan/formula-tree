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


target_link_libraries(test-sample-formula antlr4_static)
target_link_libraries(test-formula-tree antlr4_static)
target_link_libraries(test-leaf-configs antlr4_static)
target_link_libraries(test-leaf-configs-2 antlr4_static)
