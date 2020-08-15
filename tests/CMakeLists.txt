cmake_minimum_required(VERSION 3.7)

include(ExternalCatch2)

set(TEST_SOURCE_LIST
        test-formula-tree.cpp)
        
set(TARGET_NAME tests)

add_executable(${TARGET_NAME}
               ${TEST_SOURCE_LIST}
              )

target_link_libraries(${TARGET_NAME} formula-tree)
target_link_libraries(${TARGET_NAME} catch2_main)

add_test(NAME ${TARGET_NAME}
         COMMAND ${TARGET_NAME} 
        )
