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

int main(int argc, char *argv[])
{
	std::map<std::string, int> CNametoCID;
	std::multimap<int, float> CIDtoCPurchase;
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
	Customer c;

	if (c.LoadCustomers(CIDtoCustomer, argv[1]))
	{
		for (auto it = CIDtoCustomer.begin(); it != CIDtoCustomer.end(); it++)
		{
			std::cout << it->first << " " << it->second.id << " " << it->second.name << std::endl;
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

	return 0;
}