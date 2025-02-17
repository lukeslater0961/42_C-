#include "RPN.hpp"

RPN::RPN(){}

void    handleOperators(RPN *rpndata, std::string token)
{
    int a;
    int b;
    std::string var = rpndata->rpnStack.top();
    std::istringstream(var) >> a;

    rpndata->rpnStack.pop();
    var = rpndata->rpnStack.top();
    std::istringstream(var) >> b;
    rpndata->rpnStack.pop();
    if (token == "*")
    {
        int product = b * a;
        std::stringstream ss;
        ss << product;
        rpndata->rpnStack.push(ss.str());
    }
    else if (token == "-")
    {
        int product = b - a;
        std::stringstream ss;
        ss << product;
        rpndata->rpnStack.push(ss.str());
    }
    else if (token == "/")
    {
        if (b == 0 or a == 0)
            throw(DIVISIONBYZEROEXCEPTION());
        int product = b / a;
        std::stringstream ss;
        ss << product;
        rpndata->rpnStack.push(ss.str());
    }
    else if (token == "+")
    {
        int product = b + a;
        std::stringstream ss;
        ss << product;
        rpndata->rpnStack.push(ss.str());
    }
}

void    parseArgs(char *args)
{
    std::string arg = args;
    arg.erase(arg.find_last_not_of(" \t\n\r\f\v") + 1); // Trim right
    arg.erase(0, arg.find_first_not_of(" \t\n\r\f\v")); // Trim left

    if (arg.empty())
        throw(EMPTYARGSEXCEPTION());
    std::istringstream ss(arg);
    std::string token;
    RPN rpndata;

    while (ss >> token)
    {
        std::cout << "arg" <<std::endl;
        if (token.size() > 1)
            throw(INVALIDARGSEXCEPTION());
        if (token.find_first_not_of("0123456789*/-+") != std::string::npos)
            throw(INVALIDARGSEXCEPTION());
        if (!token.find_first_of("*/-+") && rpndata.rpnStack.size() == 2)
            handleOperators(&rpndata, token);
        else if (token.find_first_not_of("*/-+") && rpndata.rpnStack.size() != 2)
            throw(INVALIDFORMATEXCEPTION());
        else
            rpndata.rpnStack.push(token);
    }
    std::cout << rpndata.rpnStack.top() << std::endl;
}   