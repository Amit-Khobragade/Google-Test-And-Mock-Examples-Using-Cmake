#ifndef CHECKER_H
#define CHECKER_H

//checks the range and has only one method which takes the number and checks
//if it exists between two numbers(by default 0.0-10.0)
class RangeChecker{
public:
    RangeChecker( double dStart = 0.0 , double dEnd = 10.0 );
    bool operator()( double number );
private:
    double m_dStart;
    double m_dEnd;
};

#endif