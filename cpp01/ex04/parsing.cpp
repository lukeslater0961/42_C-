#include "sed.hpp"


int	parseArgs(char **argv)
{
	std::string	str;

	str.append(argv[1]);
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
	std::fstream File;
	File.open(argv[1], ios::out);
	if (!File)
	{
		error_mngment(FILE_CANT_OPEN);
		return (1);
	}
	File.close();
	return (0);
}
