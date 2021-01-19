cmake_minimum_required(VERSION 3.19.2)
project(firstTest VERSION 1.0)


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
enable_testing()

add_subdirectory(Account)

add_executable(accountMainTest main.cpp)

target_link_libraries( accountMainTest
account)

target_link_libraries( accountMainTest 
${GTEST_LIBRARIES} pthread)