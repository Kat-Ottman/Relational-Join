#include "Split.h"
#include <iostream>
#include <string>
#include <vector>

/*
Finds first occurance of delimeter in line and inserts characters
found between delimeter and beginning of line into vector. Repeats until
there are no more delimeters found in line.

Catches last characters in line that are without a delimeter and inserts
into vector.
*/
Split::Split(std::vector<std::string> &tokens, std::string &line, std::string &delimeter)
{
	size_t pos;
	size_t npos = -1;

	while ((pos = line.find(delimeter)) != npos)
	{
		tokens.push_back(line.substr(0, pos));
		line.erase(0, pos + delimeter.length());
	}

	if (line.length() > 0)
	{
		tokens.push_back(line);
	}
}