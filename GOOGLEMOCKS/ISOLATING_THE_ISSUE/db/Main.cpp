#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "otherClass.h"
#include "someClass.h"

class mockOtherClass: public otherClass{
    public:
        mockOtherClass( float val )
			:otherClass(val)
		{}
		MOCK_CONST_METHOD( float, method_to_check, (int) );
};

TEST( test_1, testOther ){
	float val{20.00};
	mockOtherClass mo{val};
	someClass sc(&mo);
	EXPECT_CALL(mo, method_to_check(testing::_)).Times(1);//.WillOnce(testing::Return(val));
	float retVal = sc.method_to_forward( 2 );
	ASSERT_EQ(retVal, val);
}

int main(int argc,char* argv[]){
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}