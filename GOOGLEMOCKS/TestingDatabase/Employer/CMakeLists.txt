add_library(employer 
src/EmployeeManager.cpp)

target_include_directories(employer PUBLIC include )
target_include_directories(employer PUBLIC ../IDatabaseConnection/include )
