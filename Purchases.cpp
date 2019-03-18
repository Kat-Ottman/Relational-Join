#include <map>
#include <iostream>
#include "Purchases.h"
#include <fstream>
#include <sstream>
#include "Split.h"
#include <vector>
#include <string>
#include <list>

bool SafeFloatFromString(std::string &input, float &v)
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

Purchases::Purchases(std::string id, std::string invoice, std::string date, float amout)
{
	this->id = id;
	this->invoice = invoice;
	this->date = date;
	this->amount = amount;
}
bool Purchases::LoadPurchase(std::multimap<std::string, float> &ptable, const std::string filename, bool verbose)
{
	std::ifstream infile(filename);

	std::list<Purchases> pod;

	if (infile.is_open())
	{
		std::string line;

		while (getline(infile, line))
		{
			std::vector<std::string> space;

			if (line == "")
				continue;

			Split(&space, &line);

			std::string badge = space.at(0);
			std::string check = space.at(1);
			std::string duration = space.at(2);
			float number = 0.0;

			/* 			if (SafeFloatFromString(space.at(3), number))
			{ */
			number = stof(space.at(3));
			/* 			}
			else
			{
				std::cerr << "Unable to convert string to float." << std::endl;
				return false;
			} */

			Purchases p = Purchases(badge, check, duration, number);

			pod.push_back(p);
		}
	}
	infile.close();

	for (auto it = pod.begin(); it != pod.end(); ++it)
	{

		Purchases newOne = *it;

		ptable.insert(std::pair<std::string, float>(newOne.id, newOne.amount));

		return true;
	}

	return verbose;
}
