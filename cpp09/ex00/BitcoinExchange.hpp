#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>

# define CANT_OPEN "Can't open file"
# define FILE_EMPTY "File is empty"
# define INV_FORMAT "Invalid format"
# define NON_EXIST "Date doesn't exist"

struct BitcoinData{

    BitcoinData();

    std::string strDate;
    float currentValue;
    bool  isOpen;

    std::map<std::string, float> bitcoin;
};


int   checkValue(std::string value, BitcoinData *bitcoindata);
int    checkDate(std::string dateValue, BitcoinData *bitcoindata);
void    printValues(BitcoinData *bitcoindata);
struct  tm getDate(std::string dateValue);
#endif