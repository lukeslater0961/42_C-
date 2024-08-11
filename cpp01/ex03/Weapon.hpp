#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class	Weapon
{
	public :
		Weapon(const std::string &Type);
		~Weapon();
		const	std::string& getType() const;
		void	setType(const std::string &newWeaponType);

	private :
		std::string	_type;
};
#endif
