/*	Project:    P3
	Name:       Kat Ottman
    Partner:    Darryl McCottrell
    Class:      CSC 1820 - Section 1
*/

/* making one map for company data with keys for company id and values being the rest of the line
		> companyID to companyData
		> Step 2: get company information
   making one map to find company Id
		> name to companyID
		> Step 1: get companies in alphabetical order
		> think of as index of first map by company name
   making one multimap to add transactions of companies
		> multimaps have unique keys with multiple values (multiple transactions of companies)
		> companyID to transactionData
		> Step 3

   check out <iomanip> for tools with strings
		> 9.3 in zybooks
		> use setw(anyNumber) to create column sizes

		*/

#include <iostream>
#include <map>
#include <Customer.h>
#include <fstream>

int main(int argc, char *argv[])
{
	std::map<std::string, int> CNametoCID;
	std::multimap<int, float> CIDtoCPurchase;
	std::map<int, Customer> CIDtoCustomer;

	if (argc < 3)
	{
		std::cerr << "Must provide 2 file names" << std::endl;
		return 0;
	}

	/*
	ifstream infile reads in the argv[1] and uses the Customer
	function LoadCustomer() and Customer() to create new customers based on each line of
	the text file at argv[1]. It also emplaces the customer IDs and the customer info
	into the map CIDtoCustomer in the respective pair places <int, Customer>
	*/
	std::ifstream infile(argv[1]);
	if (infile.is_open())
	{
	}
	else
	{
		std::cerr << "Unable to open file: " << argv[1] << std::endl;
	}

	/*
	ifstream infile2 is read in the argv[2] and uses the Purchases fuction LoadPurchase()
	and Purchase() to create new purchases based on each line of the text file at argv[2].
	It also emplaces the customer Ids and the customer purchase history into the
	multimap CIDtoCpurchase in the respective pair places <int, float>.
	*/
	std::ifstream infile2(argv[2]);
	if (infile2.is_open())
	{
	}
	else
	{
		std::cerr << "Unable to open file: " << argv[2] << std::endl;
	}

	/*
	The CNametoCID map is created based on the CIDtoCInfo map using the
	key and the first constructor of the CIDtoCInfo map.
	*/

	return 0;
}