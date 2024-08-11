#include "Weapon.hpp"
#include <string>
#include <iostream>

class	HumanB
{
	public :
		HumanB(const std::string &name);
		~HumanB();
		void	setWeapon(Weapon &weapon);
		void	attack();

	private :
		std::string	_name;
		Weapon		*_weapon;
};
