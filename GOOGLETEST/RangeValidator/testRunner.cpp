#include <iostream>
// #include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "checker.h"

/////////////////////////////////////////////////////////////
//fixture class for parameters
class RangeCheckerFixture: public testing::TestWithParam<double>{
public:
    RangeCheckerFixture() = default;
protected:
    RangeChecker range{ 0.0, 100.0 };
};
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
//test with param
TEST_P( RangeCheckerFixture, TEST_IN_RANGE ){
    int param = GetParam();
    std::cout<< "\n\n" <<param << "\n\n";
    bool testval= range( param );
    ASSERT_TRUE( testval );
}
/////////////////////////////////////////////////////////////

INSTANTIATE_TEST_CASE_P( TEST_IN_RANGE, RangeCheckerFixture, testing::Values(1,20,30,40,120));

int main( int argc, char* argv[] ){
    testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}