#pragma once

#include <iostream>
#include <map>
#include <vector>

class Customer
{
  public:
	Customer();
	Customer(std::string id, std::string name, std::string street, std::string city, std::string state, std::string zipcode);

	static bool LoadCustomers(std::map<std::string, Customer> &CInfo, const std::string filename, bool verbose = false);

	std::string id;
	std::string name;
	std::string street;
	std::string city;
	std::string state;
	std::string zipcode;
};