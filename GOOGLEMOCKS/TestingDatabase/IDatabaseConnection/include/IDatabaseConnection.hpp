#pragma once
#include <string>
#include <vector>
#include "../../Employee.hpp"

//interface because we might subclass it
//example: IOracleDatabaseConnectionManager, ISQLDatabaseConnectionManager
class IDatabaseConnection
{
	public:
		IDatabaseConnection(std::string serverAddress);


		virtual float getSalary(int id) const;
		virtual void updateSalary(int id, float newSalary);

		virtual std::vector<Employee> getSalariesRange(float low) const;
		virtual std::vector<Employee> getSalariesRange(float low, float high) const;

		virtual void connect();
		virtual void disconnect();

	protected:
  		std::string mServerAddress;
	private:
  		std::vector<Employee> allEmployees;
};
