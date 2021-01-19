#include "IDatabaseConnection.hpp"
#include <limits>
#include <iostream>

IDatabaseConnection::IDatabaseConnection(std::string serverAddress) 
	: mServerAddress{serverAddress}
{
	Employee e1{ 1, 20.00, "aniler" };
	Employee e2{ 2, 40.00, "anil" };
	Employee e3{ 3, 20.00, "annita" };
	Employee e4{ 4, 60.00, "annie" };

	allEmployees.push_back(e1);
	allEmployees.push_back(e2);
	allEmployees.push_back(e3);
	allEmployees.push_back(e4);
}

float IDatabaseConnection::getSalary(int id) const { 
	for(Employee item: allEmployees)
		if( item.id == id )
			return item.salary;
	return -1.0;
}
void IDatabaseConnection::updateSalary(int id, float newSalary) {
	for(Employee& item: allEmployees)
		if( item.id == id ){
			item.salary = newSalary;
			break;
		}
}

std::vector<Employee> IDatabaseConnection::getSalariesRange(float low) const {
	return getSalariesRange( low, std::numeric_limits<float>::max() );
}
std::vector<Employee> IDatabaseConnection::getSalariesRange(float low, float high) const {
	std::vector<Employee> temp;
	for(Employee item: allEmployees)
		if( item.salary > low && item.salary < high )
			temp.push_back(item);
	return temp;
}

void IDatabaseConnection::connect()
{
  std::cout << "Connecting to database server " << mServerAddress << "\n";
}

void IDatabaseConnection::disconnect()
{
 std::cout << "Disconnecting from database\n";
}