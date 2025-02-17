#include "BitcoinExchange.hpp"

BitcoinData::BitcoinData()
{
    std::string date, value;
    std::ifstream csv("data.csv");
    if (csv)
    {
        isOpen = true;
        while (std::getline(csv, date, ',') && std::getline(csv, value))
            bitcoin[date] = std::strtof(value.c_str(), NULL);
    }
    else
    {
        csv.close();
        isOpen = false;
    }
}

int    checkDate(std::string dateValue, BitcoinData *bitcoindata)
{
    int year, month , day;
    char garbage;
    std::istringstream  ss(dateValue);
    struct tm date;

    if (dateValue.empty())
    {
        std::cerr << "Error: Missing value for date " << dateValue << std::endl;
        return (1);
    }
    ss >> year >> garbage >> month >> garbage >> day;
    memset(&date, 0, sizeof(date));
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;
    mktime(&date);
    if((date.tm_mon != (month - 1)) || (date.tm_mday != day))
    {
        std::cerr << "Error: Invalid date => " << dateValue << std::endl;
        return (1);
    }
    bitcoindata->strDate = dateValue;
    return (0);
}


int   checkValue(std::string value, BitcoinData *bitcoindata)
{
    char *garbage;
    if (value.empty())
    {
        std::cerr << "Error: Missing value " << std::endl;
        return (1);
    }
    float num = std::strtof(value.c_str(), &garbage);

    if (garbage[0])
    {
        std::cerr << "Error: invalid value= " << value << std::endl;
        return (1);
    }
    else if (!(num >= 0))
    {
        std::cerr << "Error: not a positive number" << std::endl;
        return (1);
    }
    else if (!(num <= 1000))
    {
        std::cerr << "Error: too large a number" << std::endl;
        return (1);
    }
    bitcoindata->currentValue = num;
    return (0);
}

void    printValues(BitcoinData *bitcoindata)
{ 
    std::map<std::string, float>::iterator it = bitcoindata->bitcoin.upper_bound(bitcoindata->strDate);

    if (it == bitcoindata->bitcoin.begin())
        std::cerr << "Error: no lower date found" <<std::endl;
    else
    {
        if (it != bitcoindata->bitcoin.end())
            it--;
        std::cout << it->first << " => " << bitcoindata->currentValue << " = " << bitcoindata->currentValue * it->second <<std::endl;
    }
}