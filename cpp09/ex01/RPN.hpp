#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <cstring>
#include <exception>
#include <stack>
#include <string>
#include <sstream>


#define INV_ARG_NUM "Invalid number of arguments"

class INVALIDARGSEXCEPTION : public std::exception{
    public:
        const char* what() const throw(){
            return "Invalid arg found in the parameters";
        }
};

class CHAROCCURENCEEXCEPTION : public std::exception{
    public:
        const char *what() const throw(){
            return "Multiple back to back operators found";
        }
};

class INVALIDFORMATEXCEPTION : public std::exception{
    public:
    const char* what() const throw(){
        return "Invalid format";
    }
};

struct RPN{
    public:
        RPN();
        std::stack<char>    rpnStack;
} ;

void    parseArgs(char *args);
#endif 