
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	luke("luke");
	ClapTrap	louis;
	for (int i = 0; i < 9; i++)
		luke.beRepaired(1);
	luke.attack("louis");
	louis.attack("dummy");
	louis.takeDamage(30);
	louis.attack("dummy2");
	for (int i = 0; i < 10; i++)
		louis.beRepaired(1);
}
