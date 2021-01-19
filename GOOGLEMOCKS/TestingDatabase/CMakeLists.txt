cmake_minimum_required( VERSION  3.19.2 )
project( database VERSION 1.0 )  

set(CMAKE_CXX_STANDARD 17)

#################################################################
################# find gmoc and gtest ###########################
#################################################################
find_package( GTest REQUIRED )
include_directories(  ${GTEST_INCLUDE_DIRS} )

find_package( GMock REQUIRED )
include_directories( ${GMOCK_INCLUDE_DIRS} )
enable_testing()


#################################################################
################## adding subdirectory ##########################
#################################################################


add_subdirectory(Employer)
add_subdirectory(IDatabaseConnection)


#################################################################
################# adding executable #############################
#################################################################

add_executable( testRunner 
testRunner.cpp
employee.hpp
)

#################################################################
################## linking libraries ############################
#################################################################


target_link_libraries( testRunner
${GTEST_LIBRARIES} 
${GMOCK_BOTH_LIBRARIES}
pthread
employer
dbconnection
)
