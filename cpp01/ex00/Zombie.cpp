
#include "Zombie.hpp"

Zombie::Zombie(){std::cout<<"zombie created"<<std::endl;}

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
