#include <iostream>
#include "Customer.h"
#include <map>

Customer::Customer(std::string id, std::string name, std::string street, std::string city, std::string state, std::string zipcode)
{
}

bool Customer::LoadCustomers(std::map<std::string, Customer> &CInfo, const char *filename, bool verbose)
{
	return verbose;
}