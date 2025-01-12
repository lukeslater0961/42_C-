#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

class NOOCCURENCE{
	public:
		const char* what() const throw()
		{
			return ("No occurence found");
		}
};

template <typename T>
void	easyfind(T container, int num)
{
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
	{
		if (*it == num)
		{
			std::cout << "num is found in the container" << std::endl;
			return;
		}
	}
	throw (NOOCCURENCE());
}


#endif
