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
	in the argv[1] file. Only after this is completed, using the Purchases class,
	the CIDtoCPurchase map will be populated by the lines in the argv[2] file.
	Then, the CNametoCID map will be created using the first map. If this fails,
	the program will stop.
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
	Results from all maps and multimap are printed out in a sales summary report.
	Results are sorted alphabetically. This will print out an error if a
	Customer cannot be found.
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

	for (auto iterator = CNametoCID.begin(); iterator != CNametoCID.end(); iterator++)
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
		float CPAmount = 0.00;

		/*
		Total does not print correctly. The std::fixed function overrides the adding
		onto CPAmount so that it reverts back to the original initialization of the
		variable.
		*/
		for (auto iter = CIDtoCPurchase.begin(); iter != CIDtoCPurchase.end(); iter++)
		{
			if ((*(iter)).first == SECOND1)
			{
				counter++;
				CPAmount += (*(iter)).second;
			}
		}

		std::cout << std::setw(12) << counter;
		std::cout << std::setprecision(2);
		std::cout << std::fixed << CPAmount << std::endl;
	}

	return 0;
}