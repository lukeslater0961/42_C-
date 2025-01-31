#include "PmergeMe.hpp"

mergeMeData::mergeMeData(){}

void    getValues(char **argv, mergeMeData& mergeMe)
{
    argv++;
    while (*argv)
    {
        mergeMe.token += *argv;
        mergeMe.token += " ";
        argv++;
    }
}

void    mergeMe(char **argv)
{
    int num;
    std::string value;
    mergeMeData mergeme;

    getValues(argv, mergeme);
    std::istringstream ss(mergeme.token);

    while (ss >> value)
    {
        std::istringstream(value) >> num;
        mergeme.mergeMe.push_back(num);
    }
    std::cout << mergeme.mergeMe.front() << std::endl;
}