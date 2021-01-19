cmake_minimum_required(VERSION 3.19.2)

project(RangeValidator VERSION 1.0)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
enable_testing()

add_subdirectory(rangeChecker)

add_executable(testrun 
testRunner.cpp)

target_link_libraries(testrun checker)
target_link_libraries( testrun  
${GTEST_LIBRARIES} pthread)
