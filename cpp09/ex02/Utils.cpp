#include "PmergeMe.hpp"

void    setTime(mergeMeData* mergeme, int sortState, int sortType)
{
    if(!mergeme->startSet && !sortState)
    {
        if (sortType == 1)
            mergeme->vstart = std::clock();
        else if (sortType == 2)
            mergeme->dstart = std::clock();
        mergeme->startSet = true;
        return ;
    }
    else if (sortState ==  1)
    {
        if (sortType == 1)
            mergeme->vend = std::clock();
        else if (sortType == 2)
            mergeme->dend = std::clock();
    }
}

void    printOutput(mergeMeData* mergeme, std::vector<int> vfpairs)
{
	int size = mergeme->mergeMe.size();
    std::cout << std::setprecision(256);
    std::cout << "Before: " << mergeme->token << std::endl << std::endl;

    std::cout << "After: ";
    for(std::vector<int>::iterator it = vfpairs.begin(); it != vfpairs.end(); it++)
        std::cout << *it << " ";
	if (mergeme->hasStraggler)
		size += 1;
    std::cout  << std::endl << std::endl << "Time to process a range of " << mergeme->mergeMe.size() << " elements with std::vector :" << double(mergeme->vend - mergeme->vstart) * (1000000 / CLOCKS_PER_SEC) << "us" << std::endl; 
    std::cout  << "Time to process a range of " << mergeme->mergeMe.size() << " elements with std::deque :" << double(mergeme->dend - mergeme->dstart) * (1000000 / CLOCKS_PER_SEC) << "us" << std::endl; 
}
