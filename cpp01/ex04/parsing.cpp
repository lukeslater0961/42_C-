#include "sed.hpp"
#include <fstream>

int	parseArgs(char **argv)
{
	std::string	str;
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	str.append(argv[1]);
	if (s1.empty() || s2.empty())
	{
		error_mngment(EMPTY_ARG);
		return (1);
	}
	return (0);
}

int	CheckAndOpen(std::ifstream &inFile)
{
	if (!inFile)
	{
		inFile.close();
		error_mngment(FILE_CANT_OPEN);
		return (1);
	}
	else if (inFile.peek() == std::ifstream::traits_type::eof())
	{
		inFile.close();
		error_mngment(FILE_EMPTY);
		return (1);
	}
	return (0);
}
