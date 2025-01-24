#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin()
{
    std::string date, value;

    std::ifstream csv("data.csv");
    while (std::getline(csv, date, ',') && std::getline(csv, value))
    {
        bitcoin[date] = std::strtof(value.c_str(), NULL);
        std::cout << date << " " << bitcoin[date] <<std::endl;
    }
}

void    checkValue(std::string value)
{
    char *garbage;
    float num = std::strtof(value.c_str(), &garbage);
    if (garbage[0])
        std::cout << "invalid value= " << value << std::endl;
    else if (!(num >= 0))
        std::cout << "Error: not a positive number" << std::endl;
    else if (!(num <= 1000))
        std::cout << "Error: too large a number" << std::endl;
    else
        std::cout << num << std::endl;
}
