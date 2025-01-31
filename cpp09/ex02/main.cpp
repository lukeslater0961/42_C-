#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        return (1);
    }
    try
    {
        mergeMe(argv);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}