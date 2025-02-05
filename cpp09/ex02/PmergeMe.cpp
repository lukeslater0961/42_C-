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
}

void    mergeMe(char **argv)
{
    mergeMeData mergeme;
    parseValues(argv, &mergeme);
    setValues(&mergeme);
    std::vector<t_pair> new_pairs = fordJohnson(mergeme.indiv);
    std::cout << new_pairs.begin()->first << std::endl;
    std::cout << "Returning " << new_pairs.size() << " pairs from fordJohnson" << std::endl;
}