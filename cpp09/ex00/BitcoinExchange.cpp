#include "BitcoinExchange.hpp"
#include <regex.h>
#include <string>

BitcoinData::BitcoinData(){};

int checkCsvValues(std::string date, regex_t regex, std::string value)
{
    char *garbage;
    int reg = regexec(&regex, date.c_str(), 0, NULL, 0);
    if (reg != 0)
    {
        std::cerr << "Error: " << INV_FORMAT << " in Csv " << std::endl;
        return (1);
    }
    if (value.empty())
    {
        std::cerr << "Error: missing value in Csv for date => " << date << std::endl;
        return (1);
    }
    float num = std::strtof(value.c_str(), &garbage);
    if (garbage[0])
    {
        std::cerr << "Error: invalid value Csv =>" << value << std::endl;
        return (1);
    }
    else if (!(num >= 0))
    {
        std::cerr << "Error: not a positive number Csv => " << num << std::endl;
        return (1);
    }
    return (0);
}

int parseCsv(std::ifstream& csv, BitcoinData* bitcoin)
{
    std::string date, value, firstLine;
    std::getline(csv, firstLine);
    if (strncmp(firstLine.c_str(), "date,exchange_rate", 18) != 0)
    {
        std::cerr << "Error: " << INV_FORMAT << " in Csv => " << firstLine << std::endl; 
        return (1);
    }
    regex_t regex;
    const char *pattern = "^[0-9]{4}-(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01])$";
    regcomp(&regex, pattern, REG_EXTENDED);
    while (std::getline(csv, date, ',') && std::getline(csv, value))
    {
        if (checkCsvValues(date, regex, value))
        {
            regfree(&regex);
            return (1);
        }
        bitcoin->bitcoin[date] = std::strtof(value.c_str(), NULL);
    }
    regfree(&regex);
    return (0);
}

int handleCsv(BitcoinData* bitcoin)
{
    std::ifstream csv("data.csv");
    if (!csv || csv.peek() == std::ifstream::traits_type::eof())
    {
        csv.close();
        return (1);
    }
    else if (parseCsv(csv, bitcoin))
    {
        csv.close();
        return (1);
    }
    return (0);
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

    const char *pattern = "^[0-9]{4}-(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01])$";
    regex_t regex;
    int reg = regcomp(&regex, pattern, REG_EXTENDED);
    reg = regexec(&regex, dateValue.c_str(), 0, NULL, 0);
    regfree(&regex);
    
    if (reg != 0)
    {
        std::cerr << "Error: Invalid date format => " << dateValue << std::endl;
        return 1;
    }

    if (!(ss >> year >> garbage >> month >> garbage >> day))
    {
        std::cerr << "Error: Invalid date format => " << dateValue << std::endl;
        return 1;
    }
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
        std::cout << it->first << " => " << bitcoindata->currentValue << " = " << bitcoindata->currentValue * it->second <<std::endl;
    else
    {
        if (it != bitcoindata->bitcoin.end())
            it--;
        std::cout << it->first << " => " << bitcoindata->currentValue << " = " << bitcoindata->currentValue * it->second <<std::endl;
    }
}