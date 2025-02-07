#include "PmergeMe.hpp"

std::vector<std::pair<int, int> >    setValues(mergeMeData *mergeme)
{
    std::vector<std::pair<int, int> > vpairs;
    
    if ((mergeme->mergeMe.size() % 2) != 0)
    {
        std::cout << "straggler found " << std::endl;
        mergeme->straggler = mergeme->mergeMe.back();
        mergeme->mergeMe.pop_back();
    }
    else
        mergeme->straggler = -1;
    for(size_t i = 0; i < mergeme->mergeMe.size(); i += 2)
        vpairs.push_back(std::make_pair(mergeme->mergeMe[i], mergeme->mergeMe[i + 1]));
    
    return(vpairs);
}

void    compare(std::vector<std::pair<int, int> > &vpairs)
{
    for(std::vector<std::pair<int, int> >::iterator it = vpairs.begin(); it != vpairs.end(); it++)
    {
        int min = std::min(it->first, it->second);
        int max = std::max(it->first, it->second);
        it->first = min;
        it->second = max;
    }
}