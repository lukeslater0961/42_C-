#include "PmergeMe.hpp"

void    SetValues(mergeMeData *mergeme)
{
    if ((mergeme->mergeMe.size() % 2) != 0)
    {
        mergeme->straggler.max = mergeme->mergeMe.back();
        std::cout << mergeme->straggler.max << std::endl;
    }
    // for (std::vector<int>::iterator it = mergeme->mergeMe.begin(); it != mergeme->mergeMe.end(); it++)
    // {
    //     t_pair  *tpair;
    //     memset(&tpair, 0, sizeof(tpair));
    //     tpair->max = *it;
    //     std::cout << tpair->max << std::endl;
    //     mergeme->indiv.push_back(*tpair);
    // }
    t_pair  tpair;
    // // memset(&tpair, 0, sizeof(tpair));
    tpair.max = 3;
    std::cout << tpair.max << std::endl;
}