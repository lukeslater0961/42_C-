#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <vector>

struct t_pair{
    t_pair *first;
    t_pair *second;
    int     max;

    t_pair(t_pair* f = NULL, t_pair* s = NULL, int m = 0) : first(f), second(s), max(m) {}
};

struct mergeMeData{
    public:
        mergeMeData();

        t_pair              straggler;  
        std::string         token;
        std::vector<int>    mergeMe;
        std::vector<t_pair> indiv;
};

class INVALIDARGSEXCEPTION: public std::exception{
    const char* what() const throw(){
        return "Error: Invalid char in argument";
    }
};

class DUPLICATEEXCEPTION: public std::exception{
    const char* what() const throw(){
        return "Error: duplicate found";
    }
};

class EMPTYARGEXCEPTION: public std::exception{
    const char* what() const throw(){
        return "Error: Empty argument in input";
    }
};

void    mergeMe(char **argv);
void    setValues(mergeMeData *mergeme);
std::vector<t_pair> fordJohnson(std::vector<t_pair> pairs);

#endif 