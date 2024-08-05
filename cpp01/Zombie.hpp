class	Zombie
{
	public :
		void	announce(void);
		std::string	getName() const;
	
	private :
		std::string	_name;
}

Zombie*	newZombie(std::string name)
{
	Zombie*	zombie = new Zombie(name);
	std::cout<<"zombie name" << zombie->getName()<<std::endl;
	return (zombie);
}
