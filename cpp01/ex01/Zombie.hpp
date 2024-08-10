#include <string>
#include <iostream>
class	Zombie
{
	public :
		Zombie();
		~Zombie();
		void		setName(std::string name); 
		void		announce(void);
		std::string	getName(void) const;

	private :
		std::string	_name;
};

Zombie	*zombieHorde(int N, std::string name);
Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
