#include <iostream>
#include <gtest/gtest.h>
#include "testClass_1.h"
#include <gmock/gmock.h>

class MockedClass: public TestClassOne{
    public:
        MockedClass() = default;
        MOCK_METHOD0( methodToBeTested, void() );
};

TEST( firstTest, TestMock ){
    MockedClass mc;
    EXPECT_CALL( mc, methodToBeTested() ).Times(1);
    mc.methodToBeTested();
}


int main( int argc, char* argv[]){
    testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}