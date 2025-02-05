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

void checkDuplicates(int value, mergeMeData *mergeme)
{
    for (std::vector<int>::iterator it = mergeme->mergeMe.begin(); it != mergeme->mergeMe.end(); it++)
    {
        if (value == *it)
            throw(DUPLICATEEXCEPTION());
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
        checkDuplicates(atoi(value.c_str()), mergeme);
        std::istringstream(value) >> num;
        mergeme->mergeMe.push_back(num);
    }
}

void    mergeMe(char **argv)
{
    mergeMeData mergeme;

    parseValues(argv, &mergeme);
    setValues(&mergeme);
    std::vector<t_pair> new_pairs = fordJohnson(mergeme.indiv);
    for (std::vector<t_pair>::iterator it = new_pairs.begin(); it != new_pairs.end(); it++)
        std::cout << "Returning " << it->max << " "<< it->first->max << std::endl;
}