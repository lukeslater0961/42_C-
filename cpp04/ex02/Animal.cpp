#include "Animal.hpp"

AAnimal::AAnimal(){std::cout << "Default Animal constructor called" << std::endl;}

AAnimal::AAnimal(const AAnimal& other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

std::string AAnimal::getType() const {return (this->type);}

void	AAnimal::setType(std::string Type){this->type = Type;}

void	AAnimal::makeSound(void) const
{
	if (this->type.empty())
		std::cout << "*Animal sounds*" << std::endl;
	else if (this->type == "Cat")
		std::cout << "miaow" << std::endl;
	else if (this->type == "Dog")
		std::cout << "WOOF" << std::endl;
}

AAnimal::~AAnimal(){std::cout << "Animal was destroyed" << std::endl;}

