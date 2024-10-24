#include "sed.hpp"

int	error_mngment(std::string errName)
{
	std::cout<< errName <<std::endl;
	return (1);
}

void	do_sed(std::ifstream *inFile, std::string filename, std::string tofind, std::string inputstring)
{
	size_t index = filename.rfind('.');
	filename.resize(filename.size() - index);
	filename += ".replace";
	std::ofstream tempfile("temp.tmp", std::ios::out);
	tempfile << inFile->rdbuf() <<std::endl;
	std::ifstream File("temp.tmp", std::ios::out);
	std::ofstream outputFile(filename.c_str());
	std::string line;
	while (std::getline(File, line))
	{

		size_t	pos = 0;
		while ((pos = line.find(tofind)) && pos <= line.length())
		{
			line.erase(pos, tofind.length());
			line.insert(pos, inputstring);
		}
		outputFile << line <<std::endl;
	}
	remove("temp.tmp");
	File.close();
	outputFile.close();
}
