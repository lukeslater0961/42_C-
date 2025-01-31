#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>

void    mergeMe(char **argv);

struct mergeMeData{
    public:
        mergeMeData();

        std::string token;
        std::vector<int>    mergeMe;
};

#endif 