
#include "Zombie.hpp"

Zombie::Zombie(){std::cout<<"zombie created"<<std::endl;}
Zombie::~Zombie(){std::cout<< _name <<", Zombie destroyed"<<std::endl;}


int	main(void)
{
	int N = 5;
	Zombie	*zombie1;
	
	zombie1 = newZombie("louis");
	zombie1->announce();
	Zombie	*horde = zombieHorde(5, "actualllllly");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	randomChump("fart");

	delete (zombie1);
	delete[] (horde);
}
