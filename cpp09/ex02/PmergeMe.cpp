#include "PmergeMe.hpp"

mergeMeData::mergeMeData(){}

void    getValues(char **argv, mergeMeData *mergeMe)
{
    argv++;
    while (*argv)
    {
        mergeMe->token += *argv;
        mergeMe->token += " ";
        argv++;
    }
}

void checkDuplicates(int value, mergeMeData *mergeme)
{
    if (mergeme->setValues.find(value) != mergeme->setValues.end())
        throw DUPLICATEEXCEPTION();
}

void parseValues(char **argv, mergeMeData *mergeme)
{
    int num;
    std::string value;

    getValues(argv, mergeme);
    std::istringstream ss(mergeme->token);

    while (ss >> value)
    {
        if(value.find_first_not_of("0123456789") != std::string::npos)
            throw(INVALIDARGSEXCEPTION());
        checkDuplicates(atoi(value.c_str()), mergeme);
        std::istringstream(value) >> num;
        mergeme->mergeMe.push_back(num);
        mergeme->dequeMe.push_back(num);
        mergeme->setValues.insert(num);
    }
}


void merge(std::vector<std::pair<int, int> > &vpairs, int left, int right, int mid)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<std::pair<int, int> > leftArray;
    std::vector<std::pair<int, int> > rightArray;
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

void sortPairs(std::vector<std::pair<int, int> > &vpairs, int left, int right)
{
    if (left < right)
    {
        int mid = left + ((right - left) >> 1);

        sortPairs(vpairs, left , mid);
        sortPairs(vpairs, mid + 1, right);
        merge(vpairs, left, right, mid);
    }
}

void fillPairs(std::vector<int> &L, std::vector<int> &pend, std::vector<std::pair<int, int> > &vpairs)
{
    for(std::vector<std::pair<int, int> >::iterator it = vpairs.begin(); it != vpairs.end(); it++)
    {
        // std::cout << "L.push_back(" << it->second << "), pend.push_back(" << it->first << ")" << std::endl;
        insert(L, it->second);
        pend.push_back(it->first);
    }
}

void    insert(std::vector<int> &L, int value)
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

std::vector<int>   binarySearchInsertion(std::vector<int> &L, std::vector<int> &pend, mergeMeData* mergeme)
{
    std::set<int> inserted_value;

    for(size_t i = 0; i < pend.size(); ++i)
    {
        if (i < pend.size() && inserted_value.find(pend[i]) == inserted_value.end())
        {
            insert(L, pend[i]);
            inserted_value.insert(pend[i]);
        }
    }

    if (mergeme->hasStraggler)
    {
        if (inserted_value.find(mergeme->straggler) == inserted_value.end())
        {
            insert(L, mergeme->straggler);
            inserted_value.insert(mergeme->straggler);
        }
    }
    return (L);
}

std::vector<int> doVectorMerge(mergeMeData* mergeme)
{
    std::vector<int> L;
    std::vector<int> pend;

    setTime(mergeme, 0, 1);
    std::vector<std::pair<int, int> > vpairs = setValues(mergeme);
    compare(vpairs);
    sortPairs(vpairs, 0, vpairs.size() - 1);
    fillPairs(L, pend, vpairs);
    std::vector<int> vfpairs = binarySearchInsertion(L, pend, mergeme);
    setTime(mergeme, 1, 1);
    return (vfpairs);
}

void    mergeMe(char **argv)
{
    mergeMeData mergeme;

    std::deque<int>  Ld;
    std::deque<int>  pendd;

    mergeme.startSet = false;
    parseValues(argv, &mergeme);

    std::vector<int> vfpairs = doVectorMerge(&mergeme);
    doDequeMerge(&mergeme);

    printOutput(&mergeme, vfpairs);

    // for(std::vector<int>::iterator it = fpairs.begin(); it != fpairs.end(); it++)
    //     std::cout << *it << " ";//to be removed
    // std::cout << std::endl << "Time to process a range of " << mergeme.mergeMe.size() << " elements with std::vector :" << double(mergeme.end - mergeme.start) * (1000000 / CLOCKS_PER_SEC) << "us" << std::endl; 

    // for(std::vector<std::pair<int, int> >::iterator it = vpairs.begin(); it != vpairs.end(); it++)
    //     std::cout << it->first << " " << it->second <<std::endl;//to be removed
}