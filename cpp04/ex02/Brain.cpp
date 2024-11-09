#include "Brain.hpp"

Brain::Brain(){std::cout << "Default Brain constructor called" << std::endl;}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain&	Brain::operator=(const Brain& other)
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	return (*this);
}

Brain::~Brain(){std::cout << "Brain destroyed" << std::endl;}
