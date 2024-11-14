
#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie1;
	
	zombie1 = newZombie("louis");
	zombie1->announce();
	randomChump("fart");

	delete (zombie1);
}
