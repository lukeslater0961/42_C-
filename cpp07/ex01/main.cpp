#include <cctype>
#include <iostream>
#include "iter.hpp"

void	print(std::string str){std::cout << str << std::endl;}

int main( void )
{
	std::string array[] = {"hello", "there !", "General", "Kenobiiii"};
	iter(array, sizeof(array)/sizeof(array[0]), print);
	return 0;
}
