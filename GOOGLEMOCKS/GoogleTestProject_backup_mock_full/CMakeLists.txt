cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 11)

#################################################################
################# find gmoc and gtest ###########################
#################################################################

find_package( GTest REQUIRED )
include_directories(${GTEST_INCLUDE_DIRS})

find_package( GMock REQUIRED )
include_directories(${GMOCK_INCLUDE_DIRS})
enable_testing()
#################################################################
#################################################################


add_library(databaseConnectionLibrary IDatabaseConnection.cpp)
add_library(employeeManagerLibrary EmployeeManager.cpp)

set(ACTUAL_LIBRARIES databaseConnectionLibrary employeeManagerLibrary)

add_executable(mainApp main.cpp)
target_link_libraries(${ACTUAL_LIBRARIES})

#################################################################
################### adding a test executable ####################
#################################################################
add_executable(testRunner testRunner.cpp)
target_link_libraries(testRunner 
    ${GTEST_LIBRARIES} 
    ${GMOCK_BOTH_LIBRARIES} 
    pthread 
    ${ACTUAL_LIBRARIES})

