#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){std::cout << "WrongAnimal default constructor called" << std::endl;}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

std::string WrongAnimal::getType() const {return (this->type);}

void	WrongAnimal::setType(std::string Type){this->type = Type;}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "*WrongAnimal sounds*" << std::endl;
}

WrongAnimal::~WrongAnimal(){std::cout << "WrongAnimal was destroyed" << std::endl;}

