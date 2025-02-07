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

struct t_pair{
    t_pair *first;
    t_pair *second;
    int     max;

    t_pair(t_pair* f = NULL, t_pair* s = NULL, int m = 0) : first(f), second(s), max(m) {}
};

static const uint64_t jacobsthal_table[] = {
    0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731,
    5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051,
    1398101, 2796203, 5592405, 11184811, 22369621, 44739243,
    89478485, 178956971, 357913941, 715827883, 1431655765,
    2863311531, 5726623061, 11453246123, 22906492245, 45812984491,
    91625968981, 183251937963, 366503875925, 733007751851, 1466015503701,
    2932031007403, 5864062014805, 11728124029611, 23456248059221, 46912496118443,
    93824992236885, 187649984473771, 375299968947541, 750599937895083, 1501199875790165,
    3002399751580331, 6004799503160661, 12009599006321323, 24019198012642645, 48038396025285291,
    96076792050570581, 192153584101141163, 384307168202282325, 768614336404564651,
    1537228672809129301, 3074457345618258603, 6148914691236517205
};

struct mergeMeData{
    public:
        mergeMeData();

        int              straggler;
        std::string         token;
        std::vector<int>    mergeMe;
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
std::vector<std::pair<int, int> >    setValues(mergeMeData *mergeme);
void    compare(std::vector<std::pair<int, int> > &vpairs);
std::vector<uint64_t> generate_jacobsthal(size_t size);
#endif 