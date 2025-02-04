#include "PmergeMe.hpp"

mergeMeData::mergeMeData(){}

void    getValues(char **argv, mergeMeData *mergeMe)
{
    argv++;
    while (*argv)
    {
        mergeMe->token += *argv;
        mergeMe->token += " ";
        argv++;
    }
}

void parseValues(char **argv, mergeMeData *mergeme)
{
    int num;
    std::string value;

    getValues(argv, mergeme);
    std::istringstream ss(mergeme->token);

    while (ss >> value)
    {
        if(value.find_first_not_of("0123456789") != std::string::npos)
            throw(INVALIDARGSEXCEPTION());
        std::istringstream(value) >> num;
        mergeme->mergeMe.push_back(num);
    }
    std::cout << mergeme->mergeMe.front() << std::endl;
}

void    mergeMe(char **argv)
{
    mergeMeData mergeme;
    parseValues(argv, &mergeme);
    SetValues(&mergeme);
}
