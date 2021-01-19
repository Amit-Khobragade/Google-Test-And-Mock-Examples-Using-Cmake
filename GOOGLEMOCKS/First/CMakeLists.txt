cmake_minimum_required( VERSION 3.19.2 )
project( mocktest VERSION 1.0)

##########################################
###### including google libraries ########
# requires a pre gtest and gmock install #
##########################################

find_package( GTest REQUIRED )
include_directories(${GTEST_INCLUDE_DIRS})

find_package( GMock REQUIRED )
include_directories(${GMOCK_INCLUDE_DIRS})
enable_testing()

##########################################
######### adding subdirectories ##########
##########################################

add_subdirectory(FirstTests)

##########################################
########## making executable #############
##########################################

add_executable(testrunner 
main.cpp)

##########################################
####### linking the left libraries #######
##########################################

target_link_libraries(testrunner
firstTest)

target_link_libraries(testrunner
${GTEST_LIBRARIES} pthread)


target_link_libraries(testrunner ${GMOCK_BOTH_LIBRARIES})