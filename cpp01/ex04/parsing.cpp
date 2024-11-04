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
	for (std::string::iterator iter = str.begin(); iter != str.end(); iter++)
	{
		if (*iter == '.' && iter != str.begin() && iter != str.end() - 1)
			return (0);
	}
	error_mngment(INVALID_FILE);
	return (1);
}

std::ifstream*	CheckAndOpen(char **argv)
{
	std::ifstream* inFile = new std::ifstream(argv[1], std::ios::in);
	if (!*inFile)
	{
		delete(inFile);
		error_mngment(FILE_CANT_OPEN);
		return (NULL);
	}
	else if (inFile->peek() == std::ifstream::traits_type::eof())
	{
		delete(inFile);
		error_mngment(FILE_EMPTY);
		return (NULL);
	}
	return (inFile);
}
