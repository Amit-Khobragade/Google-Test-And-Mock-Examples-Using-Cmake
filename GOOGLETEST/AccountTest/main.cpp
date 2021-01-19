#include <iostream>
#include <gtest/gtest.h>
#include <stdexcept>
#include "account.h"

///////////////////////////////////////////////////////////////////
//fixture class for Account
class AccountTestFixtures: public testing::Test
{
public:
	AccountTestFixtures();
	static void SetUpTestCase();
	void SetUp() override;
	void TearDown() override;
	static void TearDownTestCase();
	virtual ~AccountTestFixtures(){
		std::cout<<"\n\ndestructor\n\n";
	}
protected:
	Account accobj;
};

//method implementations
AccountTestFixtures::AccountTestFixtures()
	:accobj{"amit", 198}
{
	std::cout<<"\n\nconstructor\n\n";
}


void AccountTestFixtures::SetUpTestCase(){
	std::cout<<"\n\nsetup test case\n\n";
}

void AccountTestFixtures::SetUp() {
	std::cout<<"\n\nsetup\n\n";
	accobj.setBalance( 198.0 );
}

void AccountTestFixtures::TearDown() {
	std::cout<<"\n\nTearDown\n\n";
}

void AccountTestFixtures::TearDownTestCase(){
	std::cout<<"\n\ntear down test case\n\n";
}
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////
//test 1 :: deposit :: normal deposit
TEST_F( AccountTestFixtures, Testdeposit ){
	ASSERT_EQ( 188.0, accobj.withdrawl( 10 )); 
}
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
//test 2 :: deposit :: exception check
TEST_F( AccountTestFixtures, TestdepositSmallerThan0 ){
	ASSERT_THROW( accobj.withdrawl( -10 ), std::invalid_argument);
}
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
//test 3 :: deposit :: exception check
TEST_F( AccountTestFixtures, TestdepositNotEnoughBalance ){
	ASSERT_THROW( accobj.withdrawl( 2000 ), std::runtime_error);
}
///////////////////////////////////////////////////////////////////

int main( int argc, char* argv[] ){
	testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}
