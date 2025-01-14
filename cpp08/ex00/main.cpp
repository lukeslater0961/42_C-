#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include<cstdlib>
#include <list>

int main(int argc , char **argv)
{

	int num;

	if (argc != 2)
		return (1);
	else
		num = atoi(argv[1]);	

	std::cout << "vector test _____________________________________" << std::endl;
	std::vector<int> vecContainer;
    vecContainer.push_back(1);
    vecContainer.push_back(2);
    vecContainer.push_back(3);
    vecContainer.push_back(10);
	vecContainer.push_back(12);

	try{
		easyfind(vecContainer, num);
	}
	catch(NOOCCURENCE& e)
	{
		std::cout << "vector Exception: " << e.what() << std::endl;

	}

	std::cout << "list test _____________________________________" << std::endl;

	std::list<int> listContainer;
    listContainer.push_back(1);
    listContainer.push_back(2);
    listContainer.push_back(3);
    listContainer.push_back(10);
	listContainer.push_back(12);

	try{
		easyfind(listContainer, num);
	}
	catch(NOOCCURENCE& e)
	{
		std::cout << "list Exception: " << e.what() << std::endl;
		return (1);
	}


}
