/*	Project:    P3
	Name:       Kat Ottman
    Partner:    Darryl McCottrell
    Class:      CSC 1820 - Section 1
*/

#include <iostream>
#include <map>
#include "Customer.h"
#include <fstream>
#include "Purchases.h"
#include <iomanip>

int main(int argc, char *argv[])
{
	std::map<std::string, std::string> CNametoCID;
	std::multimap<std::string, float> CIDtoCPurchase;
	std::map<std::string, Customer> CIDtoCustomer;

	if (argc < 3)
	{
		std::cerr << "Must provide 2 file names" << std::endl;
		return 0;
	}

	/*
	Using the Customer class, the CIDtoCustomer map will be populated by the lines
	in the argv[1] file.
	*/
	Customer c = Customer("id", "name", "street", "city", "state", "zipcode");
	Purchases p = Purchases("id", "invoice", "date", 0.0);

	if (c.LoadCustomers(CIDtoCustomer, argv[1]))
	{
		if (p.LoadPurchase(CIDtoCPurchase, argv[2]))
		{

			for (auto it = CIDtoCustomer.begin(); it != CIDtoCustomer.end(); it++)
			{
				CNametoCID.emplace((*(it)).second.name, (*(it)).first);
			}

			/* for (auto iter = CNametoCID.begin(); iter != CNametoCID.end(); iter++)
		{
			std::cout << (*(iter)).first << "," << (*(iter)).second << std::endl;
		} */
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 1;
	}

	/*
	ifstream infile2 is read in the argv[2] and uses the Purchases fuction LoadPurchase()
	and Purchase() to create new purchases based on each line of the text file at argv[2].
	It also emplaces the customer Ids and the customer purchase history into the
	multimap CIDtoCpurchase in the respective pair places <int, float>.
	*/

	/*
	The CNametoCID map is created based on the CIDtoCInfo map using the
	key and the first constructor of the CIDtoCInfo map.
	*/

	std::cout << "File: " << argv[1] << " contained " << CIDtoCustomer.size() << " records." << std::endl;
	std::cout << "File: " << argv[2] << " contained " << CIDtoCPurchase.size() << " records." << std::endl;
	std::cout << "Sales summary report:" << std::endl;
	std::cout << "=====================" << std::endl;
	std::cout << std::setw(10) << std::left << "ID:";
	std::cout << std::setw(40) << "Name:";
	std::cout << std::setw(8) << "State:";
	std::cout << std::setw(12) << "Purchases:";
	std::cout << std::setw(15) << "Total:" << std::endl;

	std::string UserIn;

	std::cout << "Enter a company you would like to find: " << std::endl;
	std::cin >> UserIn;

	auto it = CNametoCID.find(UserIn);

	if (it == CNametoCID.end())
	{
		std::cerr << "Customer: " << UserIn << " could not be found." << std::endl;
	}
	else
	{
		std::cout << std::setw(10) << (*(it)).second;
		std::cout << std::setw(40) << UserIn;
	}

	auto iter = CIDtoCustomer.find((*(it)).second);

	if (iter == CIDtoCustomer.end())
	{
		std::cerr << "Customer: " << UserIn << " could not be found." << std::endl;
	}
	else
	{
		std::cout << std::setw(8) << (*(iter)).second.state;
	}

	int counter = 0;
	float CPAmount = 0.0;

	for (auto iterator = CIDtoCPurchase.begin(); iterator != CIDtoCPurchase.end(); iterator++)
	{
		if ((*(iterator)).first == (*(it)).second)
		{
			counter++;
			CPAmount += (*(iterator)).second;
		}
	}

	std::cout << std::setw(12) << counter;
	std::cout << std::setw(15) << CPAmount << std::endl;

	/* for (auto iterator = CNametoCID.begin(); iterator != CNametoCID.end(); iterator++)
	{
		std::pair<std::string, std::string> twin = (*(iterator));
		std::string FIRST1 = twin.first;
		std::string SECOND1 = twin.second;

		std::cout << std::setw(10) << SECOND1;
		std::cout << std::setw(40) << FIRST1;

		auto it = CIDtoCustomer.find(SECOND1);

		if (it == CIDtoCustomer.end())
		{
			std::cerr << "Customer: " << FIRST1 << " could not be found." << std::endl;
		}
		else
		{
			std::cout << std::setw(8) << (*(it)).second.state;
		}

		int counter = 0;
		float CPAmount = 0.0;

		for (auto iter = CIDtoCPurchase.begin(); iter != CIDtoCPurchase.end(); iter++)
		{
			if ((*(iter)).first == SECOND1)
			{
				counter++;
				CPAmount += (*(iter)).second;
			}
		}

		std::cout << std::setw(12) << counter;
		std::cout << std::setw(15) << CPAmount << std::endl;
	} */

	return 0;
}