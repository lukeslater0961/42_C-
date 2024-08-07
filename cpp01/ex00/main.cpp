
#include "Zombie.hpp"

Zombie::Zombie(){std::cout<<"zombie created"<<std::endl;}
Zombie::~Zombie(){std::cout<< _name <<", Zombie destroyed"<<std::endl;}


int	main(void)
{
	Zombie	*zombie1;
	
	zombie1 = newZombie("louis");
	zombie1->announce();
	randomChump("fart");

	delete (zombie1);
}
