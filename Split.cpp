#include "Split.h"
#include <iostream>
#include <string>
#include <vector>

Split::Split(std::vector<std::string> *tokens, std::string *line)
{
	size_t start = 0;
	size_t last = (*(line)).find_first_of(",");
	size_t npos = -1;

	while (last != npos)
	{
		if (last > start)
		{

			(*(tokens)).push_back((*(line)).substr(start, (last - start)));
		}

		start = ++last;
		last = (*(line)).find_first_of(" ", last);
	}

	(*(tokens)).push_back((*(line)).substr(start));
}