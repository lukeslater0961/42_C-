#include "RPN.hpp"

int errorMngment(std::string arg)
{
    std::cerr<< "Error: " << arg << std::endl;
    return (1);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (errorMngment(INV_ARG_NUM));
    else
    {
        try{
            if (argv[1][0])
                parseArgs(argv[1]);
            else
                throw(EMPTYARGSEXCEPTION());
        }
        catch(const std::exception& e){
            std::cerr << e.what() << std::endl;
        }
    }
}