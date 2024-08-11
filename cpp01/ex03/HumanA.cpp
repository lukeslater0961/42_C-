#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string &name, Weapon &weapon) : _name(name), weapon(weapon) {}

HumanA::~HumanA(){std::cout<< "HumanA destroyed"<<std::endl;}

void	HumanA::attack()
{
	std::cout << _name << "attacks with their weapon" << weapon.getType() <<std::endl;
}
