cmake_minimum_required(VERSION 3.10)

project(DATA_STRUCTURES C)

add_library(unidirectionalList src/unidirectionalList.c)
target_include_directories(unidirectionalList PUBLIC include)

add_executable(data_structures main.c)
target_link_libraries(data_structures unidirectionalList)

if(BUILD_TESTING OR NOT DEFINED BUILD_TESTING)
    enable_testing()

    add_executable(test_unidirectionalList tests/test_unidirectionalList.c)
    target_link_libraries(test_unidirectionalList unidirectionalList)

    add_test(NAME unidirectionalList_tests COMMAND test_unidirectionalList)
endif()
