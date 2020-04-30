cmake_minimum_required(VERSION 3.7)

add_library(catch2_main STATIC catch-main.cpp)
target_include_directories(catch2_main PUBLIC ${PROJECT_SOURCE_DIR}/tests/catch2) 

set(TEST_LIST 
    formula-tree
   )

foreach(NAME IN LISTS TEST_LIST)
  list(APPEND TEST_SOURCE_LIST test-${NAME}.cpp)
endforeach()

set(TARGET_NAME tests)

add_executable(${TARGET_NAME}
               ${ANTLR_GrammarLexer_CXX_OUTPUTS}
               ${ANTLR_GrammarParser_CXX_OUTPUTS}
               ${TEST_SOURCE_LIST}
               ${SOURCE}
              )
            target_include_directories(${TARGET_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/tests/catch2)
target_link_libraries(${TARGET_NAME} catch2_main)
target_link_libraries(${TARGET_NAME} antlr4_static)

add_test(NAME ${TARGET_NAME}
         COMMAND ${TARGET_NAME} 
        )
