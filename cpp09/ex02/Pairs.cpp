#include "PmergeMe.hpp"

void    setValues(mergeMeData *mergeme)
{
    if ((mergeme->mergeMe.size() % 2) != 0)
    {
        std::cout << "straggler found " << std::endl;
        mergeme->straggler.max = mergeme->mergeMe.back();
        mergeme->mergeMe.pop_back();
    }
    for (std::vector<int>::iterator it = mergeme->mergeMe.begin(); it != mergeme->mergeMe.end(); it++)
    {
        t_pair  tpair;
        tpair.max = *it;
        mergeme->indiv.push_back(tpair);
    }
    // for (std::vector<t_pair>::iterator it = mergeme.indiv.begin(); it != mergeme.indiv.end(); it++)
    //     std::cout << it->max << std::endl; // to be removed
}

t_pair  setPairValues(t_pair *first, t_pair *second)
{
    t_pair new_pair;

    new_pair.max = first->max;
    new_pair.first = first;
    new_pair.second = second;
    return (new_pair);
}

std::vector<t_pair> fordJohnson(std::vector<t_pair> pairs)
{
    std::vector<t_pair> new_pairs;
    for (std::vector<t_pair>::iterator it = pairs.begin(); it != pairs.end(); it++)
    {
        t_pair new_pair;    
        t_pair first = *it;

        it++;
        t_pair second = *it;
        int largest = std::max(first.max, second.max);

        std::cout  << "largest is = " << largest << std::endl;
        if (largest == first.max)
        {
            new_pair = setPairValues(&first, &second);
            std::cout << "first = " << new_pair.first->max << " second  = " << new_pair.second->max << " max int  = " << new_pair.max << std::endl;
        }
        else
        {
            new_pair = setPairValues(&second, &first);
            std::cout << "first = " << new_pair.first->max << " second  = " << new_pair.second->max << " max int  = " << new_pair.max << std::endl;
        }
        new_pairs.push_back(new_pair);
    }
    std::cout << "Returning " << new_pairs.size() << " pairs from fordJohnson" << std::endl;
    return (new_pairs);
}