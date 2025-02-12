#include "PmergeMe.hpp"

void merged(std::deque<std::pair<int, int> > &vpairs, int left, int right, int mid)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::deque<std::pair<int, int> > leftArray;
    std::deque<std::pair<int, int> > rightArray;
	leftArray.resize(n1);
	rightArray.resize(n2);
    for(int i  = 0; i < n1; ++i)
        leftArray[i] = vpairs[left + i];
    for(int i  = 0; i < n2; ++i)
        rightArray[i] = vpairs[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = left;

    while(i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            vpairs[k] = leftArray[i];
            ++i;
        }
        else
        {
            vpairs[k] = rightArray[j];
            ++j;
        }
        ++k;
    }

    while (i < n1)
    {
        vpairs[k] = leftArray[i];
        ++i;
        ++k;
    }

    while (j < n2)
    {
        vpairs[k] = rightArray[j];
        ++j;
        ++k;
    }
}

void sortdPairs(std::deque<std::pair<int, int> > &vpairs, int left, int right)
{
    if (left < right)
    {
        int mid = left + ((right - left) >> 1);

        sortdPairs(vpairs, left , mid);
        sortdPairs(vpairs, mid + 1, right);
        merged(vpairs, left, right, mid);
    }
}

void filldPairs(std::deque<int> &L, std::deque<int> &pend, std::deque<std::pair<int, int> > &vpairs)
{
    for(std::deque<std::pair<int, int> >::iterator it = vpairs.begin(); it != vpairs.end(); it++)
    {
        // std::cout << "L.push_back(" << it->second << "), pend.push_back(" << it->first << ")" << std::endl;
        dinsert(L, it->second);
        pend.push_back(it->first);
    }
}

void    dinsert(std::deque<int> &L, int value)
{
    int right = L.size() - 1;
    int left = 0;
    int pos = L.size();

    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (L[mid] < value)
            left = mid + 1;
        else
        {
            pos = mid;
            right = mid - 1;
        }
    }
    L.insert(L.begin() + pos, value);
}

std::deque<int>   binarySearchdInsertion(std::deque<int> &L, std::deque<int> &pend, mergeMeData* mergeme)
{
    std::set<int> inserted_value;

    for(size_t i = 0; i < pend.size(); ++i)
    {
        if (i < pend.size() && inserted_value.find(pend[i]) == inserted_value.end())
        {
            dinsert(L, pend[i]);
            inserted_value.insert(pend[i]);
        }
    }

    if (mergeme->hasStraggler)
    {
        if (inserted_value.find(mergeme->straggler) == inserted_value.end())
        {
            dinsert(L, mergeme->straggler);
            inserted_value.insert(mergeme->straggler);
        }
    }
    return (L);
}

void 
doDequeMerge(mergeMeData* mergeme)
{
    std::deque<int> L;
    std::deque<int> pend;

    mergeme->startSet = false;
    setTime(mergeme, 0, 2);
    std::deque<std::pair<int, int> > dpairs = setdValues(mergeme);
    dcompare(dpairs);
    sortdPairs(dpairs, 0, dpairs.size() - 1);
    filldPairs(L, pend, dpairs);
    std::deque<int> dfpairs = binarySearchdInsertion(L, pend, mergeme);
    setTime(mergeme, 1, 2);
}
