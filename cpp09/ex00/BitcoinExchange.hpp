#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

# define CANT_OPEN "Can't open file"
# define FILE_EMPTY "File is empty"


struct Bitcoin{

    Bitcoin();

    std::map<std::string, float> bitcoin;
};

void    checkValue(std::string value);

#endif