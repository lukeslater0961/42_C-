#include "sed.hpp"

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

int	CheckAndOpen(char **argv)
{
	std::ifstream inFile(argv[1]);
	if (!inFile)
	{
		error_mngment(FILE_CANT_OPEN);
		return (1);
	}
	std::cout<<"file opened"<<std::endl;
	inFile.close();
	return (0);
}
