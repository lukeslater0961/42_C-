#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

# define CANT_OPEN "Can't open file"
# define FILE_EMPTY "File is empty"
std::map<int, std::string> bitcoin;
void    checkValue(std::string value);

#endif