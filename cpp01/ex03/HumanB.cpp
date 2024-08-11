#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : _name(name), _weapon(NULL) {}
HumanB::~HumanB(){std::cout<< "destroying humanb";}

void	HumanB::attack()
{
	if (_weapon)
		std::cout << _name <<  "attacks with their" << _weapon->getType() << std::endl;
	else if (!_weapon)
		std::cout << _name << "has no weapon" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
