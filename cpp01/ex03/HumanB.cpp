#include "HumanB.hpp"

HumanB::HumanB() : _name(NULL), _weapon(NULL) {std::cout<< "default constructor called" << std::endl;}
HumanB::HumanB(const std::string &name) : _name(name), _weapon(NULL) {}
HumanB::~HumanB(){std::cout<< "destroying humanb"<<std::endl;}

void	HumanB::attack()
{
	if (_weapon)
		std::cout << _name <<  " attacks with their :" << _weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
