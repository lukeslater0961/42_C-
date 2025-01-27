#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <string>

# define CANT_OPEN "Can't open file"
# define FILE_EMPTY "File is empty"
# define INV_FORMAT "Invalid format"
# define NON_EXIST "Date doesn't exist"


struct Bitcoin{

    Bitcoin();

    std::map<std::string, float> bitcoin;
};

void    checkValue(std::string value);
void    checkDate(std::string date);
#endif