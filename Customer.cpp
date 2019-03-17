#include <iostream>
#include "Customer.h"
#include "Split.h"
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

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

	if (infile1.is_open())
	{
		std::string *line;

		while (getline(infile1, (*(line)))
		{
			std::vector<std::string> *CustomerInfo;

			if ((*(line)) == "")
			{
				continue;
			}

			std::stringstream ss((*(line)));
			Split(CustomerInfo, line);
		}
	}
	else
	{
		std::cerr << "Unable to open file: " << (filename) << std::endl;
		verbose = false;
	}

	return verbose;
}