
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	luke("luke");
	ClapTrap	louis("louis");
	ScavTrap	thomas("thomas");
	FragTrap	remi("remi");
	remi.highFivesGuys();
	thomas.attack("fart");
	for (int i = 0; i < 9; i++)
		luke.beRepaired(1);
	luke.attack("louis");
	louis.attack("dummy");
	louis.takeDamage(30);
	louis.attack("dummy2");
	for (int i = 0; i < 10; i++)
		louis.beRepaired(1);
	for (int i = 0; i < 10; i++)
		remi.attack("dummy 3");
	thomas.guardGate();
}
