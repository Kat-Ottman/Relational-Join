#pragma once;

#include <iostream>
#include <map>

/*
Customer class will load file containing customer information and emplace it into the 1st map
that will have a key containing the customer ID and the customer's information as the value.
*/
class Customer
{
  public:
	Customer();
	Customer(std::string id, std::string name, std::string street, std::string city, std::string state, std::string zipcode);

	static bool LoadCustomers(std::map<std::string, Customer> &CInfo, const char *filename, bool verbose = false);

	std::string id;
	std::string name;
	std::string street;
	std::string city;
	std::string state;
	std::string zipcode;

	static const int tokens_to_expect;
};