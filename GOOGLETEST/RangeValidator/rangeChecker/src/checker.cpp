#include "checker.h"
#include <stdexcept>

RangeChecker::RangeChecker( double dStart , double dEnd )
    :m_dStart{dStart}, m_dEnd{dEnd}
{
    if( dStart > dEnd )
        throw(std::invalid_argument("start should be smaller than end"));    
}


bool RangeChecker::operator()( double number ){
    bool isInRange = false;
    if( number >= m_dStart && number <= m_dEnd )
        isInRange = true;
    return isInRange;
}