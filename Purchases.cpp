#include <map>
#include <iostream>
#include "Purchases.h"
#include <fstream>
#include <sstream>
#include "Split.h"
#include <vector>
#include <string>
#include <list>

/*
Provides a check to make sure that the string can be changed into
a float. Returns false if not possible.
*/
bool Purchases::SafeFloatFromString(std::string &input, long double &v)
{
	bool returnValue = true;
	v = 0;
	try
	{
		v = stof(input);
	}
	catch (const std::invalid_argument &ia)
	{
		returnValue = false;
	}
	return returnValue;
}

/*
Sets all given strings to known strings in Purchase class to create a Purchase type variable.
*/
Purchases::Purchases(std::string id, std::string invoice, std::string date, long double amount)
{
	this->id = id;
	this->invoice = invoice;
	this->date = date;
	this->amount = amount;
}

/*
Reads in given file and separates by lines in file. Utilizes Split constructor
to parse by delimeter. Utilizes SafeFloatFromString() to ensure float
variables can be used. Creates Purchases to be added onto a list of Purchases.
Adds ID and Purchase amount into multimap.

Only returns true if full function carries out. Otherwise, returns false.
*/
bool Purchases::LoadPurchase(std::multimap<std::string, float> &ptable, const std::string filename, bool verbose)
{
	std::ifstream infile(filename);
	std::list<Purchases> pod;

	if (infile.is_open())
	{
		std::string line;
		std::string delim = ",";

		while (getline(infile, line))
		{
			std::vector<std::string> space;

			if (line == "")
			{
				continue;
			}

			Split(space, line, delim);

			std::string badge = space.at(0);
			std::string check = space.at(1);
			std::string duration = space.at(2);
			long double number = 0.0;

			if (SafeFloatFromString(space.at(3), number))
			{
				number = stof(space.at(3));
			}
			else
			{
				std::cerr << "Unable to convert string to float." << std::endl;
				return false;
			}

			Purchases p = Purchases(badge, check, duration, number);

			pod.push_back(p);
		}
	}
	else
	{
		std::cerr << "Unable to open file: " << (filename) << std::endl;
		return verbose;
	}

	infile.close();

	for (auto it = pod.begin(); it != pod.end(); ++it)
	{

		Purchases newOne = *it;

		ptable.insert(std::pair<std::string, float>(newOne.id, newOne.amount));

		verbose = true;
	}

	return verbose;
}
