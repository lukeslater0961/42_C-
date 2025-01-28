#include "RPN.hpp"

RPN::RPN(){}

void    parseArgs(char *args)
{
    std::string arg = args;

    std::istringstream ss(arg);
    std::string token;
    RPN rpndata;

    while (ss >> token)
    {
        if (token.size() > 1)
            throw(INVALIDARGSEXCEPTION());
        if (token.find_first_not_of("0123456789*/-+") != std::string::npos)
            throw(INVALIDARGSEXCEPTION());
        if (token.find_first_of("*/-+") && rpndata.rpnStack.size() == 2)
        {

        }
        else if (token.find_first_not_of("*/-+") && rpndata.rpnStack.size() != 2)
            throw(INVALIDFORMATEXCEPTION());
        else
            rpndata.rpnStack.push(*token.c_str());

        std::cout << rpndata.rpnStack.top() << std::endl;
    }
}