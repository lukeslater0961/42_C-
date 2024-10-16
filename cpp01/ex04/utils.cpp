#include "sed.hpp"

int	error_mngment(std::string errName)
{
	std::cout<< errName <<std::endl;
	return (1);
}

void	do_sed(std::ifstream *inFile, std::string filename)
{
	size_t index = filename.rfind('.');
	filename.resize(filename.size() - index);
	filename += ".replace";
	std::cout << filename << "file is this" << std::endl;
	std::ofstream outputFile(filename.c_str(), std::ios::out);
	outputFile << inFile->rdbuf() <<std::endl;
}
