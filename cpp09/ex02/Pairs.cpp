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
}

t_pair setPairValues(t_pair* first, t_pair* second)
{
    t_pair new_pair;
    
    new_pair.first = first;  
    new_pair.second = second; 
    new_pair.max = std::max(first->max, second->max);
    
    return new_pair;
}

std::vector<t_pair> fordJohnson(std::vector<t_pair> pairs)
{
    if (pairs.size() == 1)
        return pairs;

    std::vector<t_pair> new_pairs;
    for (size_t i = 0; i < pairs.size(); i += 2)
    {
        t_pair new_pair;

        if (i + 1 < pairs.size())
        {
            t_pair first = pairs[i];
            t_pair second = pairs[i + 1];
            int largest = std::max(first.max, second.max);
            
            if (largest == first.max)
            {
                new_pair = setPairValues(&first, &second);
                std::cout << "first = " << new_pair.first->max << " second  = " << new_pair.second->max << " max int  = " << new_pair.max << std::endl;// to be removed
            }
            else
            {
                new_pair = setPairValues(&second, &first);
                std::cout << "first = " << new_pair.first->max << " second  = " << new_pair.second->max << " max int  = " << new_pair.max << std::endl;// to be removed
            }
            std::cout  << "largest is = " << largest << std::endl; // to be removed
            new_pairs.push_back(new_pair);
        }
    }
    return (fordJohnson(new_pairs));
}