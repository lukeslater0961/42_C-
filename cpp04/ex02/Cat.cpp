#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Default Cat constructor called" << std::endl;
	this->type = "Cat";
	this->create_brain();
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

void	Cat::create_brain(void){this->brain = new Brain();}
Brain*	Cat::get_brain(void) const{return (this->brain);}

Cat::~Cat()
{
	std::cout << "Cat was destroyed" << std::endl;
	delete(this->brain);
}

void	Cat::makeSound(void) const
{
	std::cout << "Mew" << std::endl;
}

