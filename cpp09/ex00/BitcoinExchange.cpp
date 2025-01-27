#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin()
{
    std::string date, value;

    std::ifstream csv("data.csv");
    while (std::getline(csv, date, ',') && std::getline(csv, value))
    {
        bitcoin[date] = std::strtof(value.c_str(), NULL);
        // std::cout << date << " " << bitcoin[date] <<std::endl;
    }
}

int split_date(const std::string& date_str, int& year, int& month, int& day)
{
    size_t first_dash = date_str.find('-');
    size_t second_dash = date_str.find('-', first_dash + 1);

    if (first_dash != std::string::npos && second_dash != std::string::npos)
    {
        std::string year_str = date_str.substr(0, first_dash);
        if (year_str.size() != 4)
        {
            std::cerr << "Error : " << INV_FORMAT << " => " << date_str << std::endl;
            return (1);
        }
        std::stringstream(year_str) >> year;

        std::string month_str = date_str.substr(first_dash + 1, second_dash - first_dash - 1);
        if (month_str.size() != 2)
        {
            std::cerr << "Error : " << INV_FORMAT << " => " << date_str << std::endl;
            return (1);
        }
        std::stringstream(month_str) >> month;

        std::string day_str = date_str.substr(second_dash + 1);
        if (day_str.size() != 2)
        {
            std::cerr << "Error : " << INV_FORMAT << " => " << date_str << std::endl;
            return (1);
        }
        std::stringstream(day_str) >> day;
    } else
    {
        std::cerr << "Error : " << INV_FORMAT << " => " << date_str << std::endl;
        return (1);
    }
    return (0);
}


void    checkDate(std::string dateValue)
{
    int year, month , day;
    struct tm date;

    if (dateValue.empty())
    {
        std::cerr << "Error: Missing value for date " << dateValue << std::endl;
        return ;
    }
    if (split_date(dateValue, year, month, day))
        return ;
    memset(&date, 0, sizeof(date));
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;

    mktime(&date);

    if((date.tm_mon != (month - 1)) || (date.tm_mday != day))
        std::cerr << "Error : Invalid date => " << dateValue << std::endl;
}


void    checkValue(std::string value)
{
    char *garbage;
    if (value.empty())
    {
        std::cerr << "Error: Missing value " << std::endl;
        return ;
    }
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
