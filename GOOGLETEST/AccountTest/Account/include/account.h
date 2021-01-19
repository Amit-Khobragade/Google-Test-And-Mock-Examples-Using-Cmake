#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

class Account {
public:
    Account( std::string name, double initial_balance = 0.0 );
    double deposit( double amount = 0.0 );
    double withdrawl( double amount = 0.0 );
    void transfer( Account to_transfer,  double amount = 0.0 );
    std::string getName();
    double getBalance();
    void setBalance( double amount );
private:
    std::string name;
    double current_balance;
};


#endif