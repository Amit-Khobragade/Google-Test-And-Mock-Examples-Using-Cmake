#include "account.h"
#include <stdexcept>

Account::Account( std::string name, double initial_balance )
    :name{name},current_balance{initial_balance}
{
    if ( this->current_balance < 0 )
        throw( std::invalid_argument("current balance smaller than 0") );
}


double Account::deposit( double amount ){
    if ( amount == 0.0 )
        return this->current_balance;
    if ( amount < 0.0 )
        throw( std::invalid_argument("amount smaller than 0") );
    this->current_balance += amount;
    return this->current_balance;
}

double Account::withdrawl( double amount ){
    if ( amount == 0.0 )
        return this->current_balance;
    if ( amount < 0.0 )
        throw( std::invalid_argument("amount smaller than 0") );
    if ( this->current_balance < amount )
        throw( std::runtime_error("not enough balance"));
    this->current_balance -= amount;
    return this->current_balance;
}


void Account::transfer( Account to_transfer,  double amount ){
    this->withdrawl( amount );
    to_transfer.deposit( amount );
}


std::string Account::getName(){
    return name;
}


double Account::getBalance(){
    return this->current_balance;
}


void Account::setBalance( double amount ){
    if( amount < 0.0 ){
        this->current_balance = 0.0;
        return;
    }
    this->current_balance = amount;
}