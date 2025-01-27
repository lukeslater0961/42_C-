#include "BitcoinExchange.hpp"

int checkValues(std::ifstream &inFile)
{
    std::string value, date;

    std::string firstLine;
    std::getline(inFile, firstLine);
    while(std::getline(inFile, date))
    {
        size_t delimiterPos = date.find('|');
        if (delimiterPos != std::string::npos) 
        {
            std::string datePart = date.substr(0, delimiterPos);
            std::string valuePart = date.substr(delimiterPos + 1);
            
            datePart.erase(0, datePart.find_first_not_of(" \t"));
            datePart.erase(datePart.find_last_not_of(" \t") + 1);
            valuePart.erase(0, valuePart.find_first_not_of(" \t"));
            valuePart.erase(valuePart.find_last_not_of(" \t") + 1);
            
            BitcoinData bitcoin;
            checkDate(datePart, &bitcoin);
            checkValue(valuePart, &bitcoin);
            printValues(&bitcoin);
        }
        else
            std::cerr << "Error: " << INV_FORMAT  << " => " << date << std::endl;
    }
    return(0);
}

int parseFile(std::string filename)
{
    std::ifstream inFile(filename.c_str());

    if (!inFile)
    {
        std::cerr << CANT_OPEN << std::endl;
        return (1);
    }
    else if (inFile.peek() == std::ifstream::traits_type::eof())
    {
        std::cerr << FILE_EMPTY << std::endl;
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
        std::cerr << "Error: invalid number of arguments" << std::endl;
    else
        parseFile(static_cast<std::string>(argv[1]));
}