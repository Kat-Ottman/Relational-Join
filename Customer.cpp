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
	this->id = id;
	this->name = name;
	this->street = street;
	this->city = city;
	this->state = state;
	this->zipcode = zipcode;
}

bool Customer::LoadCustomers(std::map<std::string, Customer> &CInfo, const std::string filename, bool verbose)
{
	std::ifstream infile1(filename);
	std::list<Customer> CustomerList;

	if (infile1.is_open())
	{
		std::string line;
		std::string delim = ",";

		while (getline(infile1, line))
		{
			std::vector<std::string> CustomerInfo;

			if (line == "")
			{
				continue;
			}

			Split(CustomerInfo, line, delim);

			std::string ID = CustomerInfo.at(0);
			std::string NAME = CustomerInfo.at(1);
			std::string STREET = CustomerInfo.at(2);
			std::string CITY = CustomerInfo.at(3);
			std::string STATE = CustomerInfo.at(4);
			std::string ZIPCODE = CustomerInfo.at(5);

			Customer newCustomer = Customer(ID, NAME, STREET, CITY, STATE, ZIPCODE);
			CustomerList.push_back(newCustomer);
		}
	}
	else
	{
		std::cerr << "Unable to open file: " << (filename) << std::endl;
		return verbose;
	}

	infile1.close();

	for (auto it = CustomerList.begin(); it != CustomerList.end(); ++it)
	{
		Customer customerIT = (*(it));

		CInfo.emplace(customerIT.id, customerIT);
		verbose = true;
	}

	if (!verbose)
	{
		for (auto iter = CustomerList.begin(); iter != CustomerList.end(); ++iter)
		{
			Customer customerIter = (*(iter));
			std::cout << "Do these values match your file? Is this the right file to read from?" << std::endl;
			std::cout << customerIter.id << customerIter.name << std::endl;
		}
	}

	return verbose;
}