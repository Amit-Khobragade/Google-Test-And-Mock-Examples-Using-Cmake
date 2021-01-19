cmake_minimum_required(VERSION 3.19.2)
project( justTest VERSION 1.0 )

find_package(GTest REQUIRED)
include_directories( ${GTEST_INCLUDE_DIRS})

find_package(GMock REQUIRED)
include_directories( ${GMOCK_INCLUDE_DIRS})

add_executable(testRunner 
Main.cpp
otherClass.cpp
someClass.cpp
)

target_link_libraries(testRunner
${GTEST_LIBRARIES}
${GMOCK_BOTH_LIBRARIES}
pthread)