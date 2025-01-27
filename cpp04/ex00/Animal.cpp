#include "Animal.hpp"

Animal::Animal(){std::cout << "Animal default constructor called" << std::endl;}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

std::string Animal::getType() const {return (this->type);}

void	Animal::setType(std::string Type){this->type = Type;}

void	Animal::makeSound(void) const
{
	std::cout << "*Animal sounds*" << std::endl;
}

Animal::~Animal(){std::cout << "Animal was destroyed" << std::endl;}

