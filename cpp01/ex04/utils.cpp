#include "sed.hpp"

int	error_mngment(std::string errName)
{
	std::cout<< errName <<std::endl;
	return (1);
}

void	do_sed(std::ifstream &inFile, std::string filename, std::string tofind, std::string inputstring)
{
	filename += ".replace";
	std::ofstream outputFile(filename.c_str());
	if (!outputFile)
	{
		error_mngment(FILE_CANT_OPEN);
		return ;
	}
	std::string line;
	while (std::getline(inFile, line))
	{
		size_t	pos = 0;
		pos = line.find(tofind);
		while (pos != std::string::npos)
		{
			line.erase(pos, tofind.length());
			line.insert(pos, inputstring);
			pos = line.find(tofind, pos + inputstring.length());
		}
		outputFile << line <<std::endl;
	}
	outputFile.close();
}
