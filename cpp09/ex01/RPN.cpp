#include "RPN.hpp"

int checkDoubleOccurence(std::string arg)
{
    int freq[256] = {0};

    for (std::string::iterator it = arg.begin() ; it != arg.end(); it++)
        freq[static_cast<unsigned char>(*it)]++;

    for (int i = 0; i < 256; ++i) {
        if (!(i >= 48 && i <= 57) && freq[i] > 1)
            return (1);
    }
    return (0);
}

void    parseArgs(char *args)
{
    std::string arg = args;

    if (arg.find_first_not_of("0123456789*/-+") != std::string::npos)
        throw(INVALIDARGSEXCEPTION());
    else if (arg.at(0) < '0' || arg.at(0) > '9')
        throw(INVALIDARGSEXCEPTION());
    if (checkDoubleOccurence(arg))
        throw(CHAROCCURENCEEXCEPTION());
}