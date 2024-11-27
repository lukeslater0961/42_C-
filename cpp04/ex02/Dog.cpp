#include "Dog.hpp"

Dog::Dog(){
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->create_brain();
}

Dog::Dog(const Dog& other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog assigment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->type = other.getType();
	return (*this);
}

void	Dog::create_brain(void){this->brain = new Brain();}
Brain*	Dog::get_brain(void) const{return (this->brain);}

Dog::~Dog()
{
	std::cout << "Dog was destroyed" << std::endl;
	delete(this->brain);
}

void	Dog::makeSound(void) const
{
	std::cout << "WOOF" << std::endl;
}

