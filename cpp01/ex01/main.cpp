
#include "Zombie.hpp"

int	main(void)
{
	int N = 5;
	Zombie	*zombie1;
	
	zombie1 = new Zombie("caca");
	zombie1->announce();
	Zombie	*horde = zombieHorde(5, "actualllllly");
	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete (zombie1);
	delete[] (horde);
}
