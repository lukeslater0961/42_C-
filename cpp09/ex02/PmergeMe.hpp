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

class INVALIDARGSEXCEPTION: public std::exception{
    const char* what() const throw(){
        return "Error: Invalid char in argument";
    }
};

class EMPTYARGEXCEPTION: public std::exception{
    const char* what() const throw(){
        return "Error: Empty argument in input";
    }
};
#endif 