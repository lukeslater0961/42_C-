#include "BitcoinExchange.hpp"

int checkValues(std::ifstream &inFile)
{
    std::string value, date;

    std::string firstLine;
    std::getline(inFile, firstLine);
    while(std::getline(inFile, date, '|') && std::getline(inFile, value))
    {
        // checkDate(date);
        checkValue(value);
        Bitcoin bitcoin;
    }
    return(0);
}

int parseFile(std::string filename)
{
    std::ifstream inFile(filename.c_str());

    if (!inFile)
    {
        std::cout << CANT_OPEN << std::endl;
        return (1);
    }
    else if (inFile.peek() == std::ifstream::traits_type::eof())
    {
        std::cout << FILE_EMPTY << std::endl;
        inFile.close();
        return (1);
    }
    else if (checkValues(inFile))
        return (1);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        std::cout << "invalid number of arguments" << std::endl;
    else
        parseFile(static_cast<std::string>(argv[1]));
}