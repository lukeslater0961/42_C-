
#include "Zombie.hpp"

Zombie::Zombie(){std::cout<<"Default zombie constructor called"<<std::endl;}


Zombie::Zombie(std::string name) : _name(name){std::cout<< _name << " zombie created"<<std::endl;}

Zombie::~Zombie(){std::cout<< _name <<", Zombie destroyed"<<std::endl;}

void	Zombie::setName(std::string name)
{
	_name = name;
}

std::string	Zombie::getName(void) const
{
	return(_name);
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
