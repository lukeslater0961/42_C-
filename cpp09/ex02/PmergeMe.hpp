#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <utility>
#include <set>
#include <stdint.h>
#include <algorithm>
#include <ctime>
#include <set>
#include <iomanip>
#include <deque>

struct t_pair{
    t_pair *first;
    t_pair *second;
    int     max;

    t_pair(t_pair* f = NULL, t_pair* s = NULL, int m = 0) : first(f), second(s), max(m) {}
};

struct mergeMeData{
    public:
        mergeMeData();

        std::clock_t         vstart;
        std::clock_t         vend;
        std::clock_t         dstart;
        std::clock_t         dend;


        bool             hasStraggler;
        bool             startSet;
        int              straggler;
        std::string         token;

        std::vector<int>    mergeMe;
        std::deque<int>     dequeMe;
        std::set<int>       setValues;
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

void                                    mergeMe(char **argv);


std::vector<std::pair<int, int> >    setValues(mergeMeData *mergeme);

void                                    compare(std::vector<std::pair<int, int> > &vpairs);
void                                    setTime(mergeMeData* mergeme, int sortState, int sortType);
void                                    insert(std::vector<int> &L, int value);
void                                    printOutput(mergeMeData* mergeme, std::vector<int> vfpairs);

void    dcompare(std::deque<std::pair<int, int> > &dpairs);
std::deque<std::pair<int, int> >    setdValues(mergeMeData *mergeme);
void doDequeMerge(mergeMeData* mergeme);
void    dinsert(std::deque<int> &L, int value);


#endif 