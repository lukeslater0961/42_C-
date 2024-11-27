#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Default Cat constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this == &other)
		return (*this);
	this->type = other.getType();
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "miaow" << std::endl;
}

Cat::~Cat(){std::cout << "Cat was destroyed" << std::endl;}

