#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Default WrongCat constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this == &other)
		return (*this);
	this->type = other.getType();
	return (*this);
}

void	WrongCat::MakeSound(void) const{
	std::cout << "WrongMew" << std::endl;
}

WrongCat::~WrongCat(){std::cout << "WrongCat was destroyed" << std::endl;}

