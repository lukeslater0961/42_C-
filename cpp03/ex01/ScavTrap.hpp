#include "ClapTrap.hpp"

class	ScavTrap: public ClapTrap{
	public:
		ScavTrap(std::string name);
		~ScavTrap();

		void		guardGate(void);
		void		attack(const std::string &target);
};
