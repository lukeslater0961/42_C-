#include "FragTrap.hpp"

FragTrap::FragTrap(std::string Name): ClapTrap(Name){
	std::cout << "FragTrap " << Name <<" was created !" << std::endl;
	Hitpoints = 100;
	Energypoints = 100;
	Attackdamage = 30;
};

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy assigment called" << std::endl;
	*this = other;
}

FragTrap::~FragTrap(){std::cout << "FragTrap " << Name << " was destroyed" << std::endl;}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this == &other)
		return (*this);
	this->Name = other.Name;
	this->Hitpoints = other.Hitpoints;
	this->Energypoints = other.Energypoints;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	if (this->Hitpoints > 0)
		std::cout << "FragTrap " << Name << "High five anyone ?" << std::endl;
	else
		std::cout << "FragTrap " << Name << " has no more Hitpoints left" << std::endl;
}
