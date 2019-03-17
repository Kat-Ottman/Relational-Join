#include <iostream>
#include "Customer.h"
#include "Split.h"
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>

Customer::Customer(std::string id, std::string name, std::string street, std::string city, std::string state, std::string zipcode)
{
	id = this->id;
	name = this->name;
	street = this->street;
	city = this->city;
	state = this->state;
	zipcode = this->zipcode;
}

bool Customer::LoadCustomers(std::map<std::string, Customer> &CInfo, const std::string filename, bool verbose)
{
	std::ifstream infile1(filename);
	std::list<Customer> CustomerList;

	if (infile1.is_open())
	{
		std::string *line = NULL;

		while (getline(infile1, (*(line))))
		{
			std::vector<std::string> *CustomerInfo = NULL;

			if ((*(line)) == "")
			{
				continue;
			}

			Split(CustomerInfo, line);

			std::string ID = (*(CustomerInfo)).at(0);
			std::string NAME = (*(CustomerInfo)).at(1);
			std::string STREET = (*(CustomerInfo)).at(2);
			std::string CITY = (*(CustomerInfo)).at(3);
			std::string STATE = (*(CustomerInfo)).at(4);
			std::string ZIPCODE = (*(CustomerInfo)).at(5);

			Customer newCustomer = Customer(ID, NAME, STREET, CITY, STATE, ZIPCODE);
			CustomerList.push_back(newCustomer);
		}
	}
	else
	{
		std::cerr << "Unable to open file: " << (filename) << std::endl;
		verbose = false;
	}

	infile1.close();

	for (auto it = CustomerList.begin(); it != CustomerList.end(); ++it)
	{
		Customer customerIT = (*(it));

		CInfo.emplace(customerIT.id, customerIT);
		verbose = true;
	}

	return verbose;
}