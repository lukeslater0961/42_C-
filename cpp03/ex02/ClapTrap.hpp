#ifndef CLAPTRAP_HPP
#define	CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap{
	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();

		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

	protected:
		int			Hitpoints;
		int			Energypoints;
		int			Attackdamage;
		std::string Name;
};

#endif
