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
    for (std::vector<int>::iterator it = mergeme->mergeMe.begin(); it != mergeme->mergeMe.end(); it++)
    {
        if (value == *it)
            throw(DUPLICATEEXCEPTION());
    }
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
    }
}


void merge(std::vector<std::pair<int, int> > &vpairs, int left, int right, int mid)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<std::pair<int, int> > rightArray;
    std::vector<std::pair<int, int> > leftArray;
	leftArray.resize(n1);
	rightArray.resize(n2);
    for(int i  = 0; i < n2; ++i)
        rightArray[i] = vpairs[mid + 1 + i];
    for(int i  = 0; i < n1; ++i)
        leftArray[i] = vpairs[left + i];

    int i = 0;
    int j = 0;
    int k = left;

    while(i < n1 && j < n2)
    {
        if (leftArray[i] < rightArray[j])
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
        std::cout << "L.push_back(" << it->second << "), pend.push_back(" << it->first << ")" << std::endl;
        L.push_back(it->second);
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
    std::cout << "Inserting " << value << " at position " << pos << std::endl;
    L.insert(L.begin() + pos, value);
}

std::vector<int>   binarySearchInsertion(std::vector<int> &L, std::vector<int> &pend)
{
    std::vector<uint64_t> jacobsthal_seq = generate_jacobsthal(pend.size());
    std::set<int> inserted_value;

    for(size_t i = 0; i < jacobsthal_seq.size(); ++i)
    {
        size_t insert_idx = jacobsthal_seq[i];
        if (insert_idx < pend.size() && inserted_value.find(pend[insert_idx]) == inserted_value.end())
        {
            insert(L, pend[insert_idx]);
            inserted_value.insert(pend[insert_idx]);
        }
    }

    for(size_t i = 0; i < pend.size(); ++i)
    {
        if (inserted_value.find(pend[i]) == inserted_value.end())
        {
            insert(L, pend[i]);
            inserted_value.insert(pend[i]);
        }
    }

    return (L);
}

bool check_if_sorted(const std::vector<int>& arr)
{
	for (size_t i = 1; i < arr.size(); ++i) {
		if (arr[i] < arr[i - 1]) {
			return 1;
		}
	}
    return 0;
}

void    mergeMe(char **argv)
{
    mergeMeData mergeme;
    std::vector<int> L;
    std::vector<int> pend;

    parseValues(argv, &mergeme);
    std::vector<std::pair<int, int> > vpairs = setValues(&mergeme);

    compare(vpairs);
    sortPairs(vpairs, 0, vpairs.size() - 1);
    fillPairs(L, pend, vpairs);
    std::vector<int> fpairs = binarySearchInsertion(L, pend);

    for(std::vector<std::pair<int, int> >::iterator it = vpairs.begin(); it != vpairs.end(); it++)
        std::cout << it->first << " " << it->second <<std::endl;//to be removed
    for(std::vector<int>::iterator it = fpairs.begin(); it != fpairs.end(); it++)
        std::cout << *it <<std::endl;//to be removed
}