#include <iostream>
#include <string>
#include <gtest\gtest.h>
#include <gmock\gmock.h>
#include <stdexcept>
#include "IDatabaseConnection.hpp"
#include "EmployeeManager.hpp"


/////////////////////////////////////////////////////////////////////////////
//////////////////////// mock class /////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
class MockDatabaseConnection: public IDatabaseConnection{
    public:
    MockDatabaseConnection( std::string serverAddress );
    MOCK_METHOD0(connect, void());
    MOCK_METHOD0(disconnect, void());

    MOCK_CONST_METHOD1(  getSalary, float(int));
    MOCK_METHOD2(updateSalary, void(int, float) );

    MOCK_CONST_METHOD1(getSalariesRange, std::vector<Employee>(float));
    MOCK_CONST_METHOD2(getSalariesRange, std::vector<Employee>(float, float));
};

MockDatabaseConnection::MockDatabaseConnection( std::string serverAddress )
    :IDatabaseConnection(serverAddress)
{}

/////////////////////////////////////////////////////////////////////////////
//////////////////////////// test fixtures //////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
class MDCfixture: public testing::Test{
    public:
		MDCfixture() = default;

	protected:
    	MockDatabaseConnection db{ "dummyConnection" };
};



/////////////////////////////////////////////////////////////////////////////
///////////////////////////// Test method call //////////////////////////////
/////////////////////////////////////////////////////////////////////////////
TEST_F( MDCfixture, TestConnectionCalls ){
	EXPECT_CALL( db, connect() ).Times(1);
    EXPECT_CALL( db, disconnect() ).Times(1);
    EmployeeManager em{&db};
}

TEST_F( MDCfixture, TestGetSalary){
	float salary = 20.00;
    int employeeId = 1;
	
	EXPECT_CALL( db, connect() );
    EXPECT_CALL( db, disconnect() );
	EXPECT_CALL( db,  getSalary(testing::_) ).Times(1).WillOnce(testing::Return(salary));


    EmployeeManager em{&db};
    float ret_salary = em.getSalary(employeeId);
    ASSERT_EQ( salary, ret_salary );
}

TEST_F( MDCfixture, TestThrow ){	
	EXPECT_CALL( db, connect() ).Times(1).WillOnce(testing::Throw(std::runtime_error("invalid")));

    ASSERT_THROW( EmployeeManager em{&db},std::runtime_error) ;

}

ACTION(someAct){
	std::cout<< "throwing exception";
	throw std::runtime_error("invalid");
}

TEST_F( MDCfixture, TestThrowAction ){
	
	EXPECT_CALL( db, connect() ).Times(1).WillOnce(someAct());

    ASSERT_THROW( EmployeeManager em{&db},std::runtime_error) ;

}

void argFunc(){
	std::cout<< "throwing exception";
	throw std::runtime_error("invalid");	
}

TEST_F( MDCfixture, TestThrowInvoke ){
	
	EXPECT_CALL( db, connect() ).Times(1).WillOnce(testing::Invoke(argFunc));

    ASSERT_THROW( EmployeeManager em{&db},std::runtime_error) ;

}
/////////////////////////////////////////////////////////////////////////////
//////////////////////////////// main ///////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
int main( int argc, char* argv[]){
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}