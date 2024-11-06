#include "ScavTrap.hpp"
#include "ClapTrap.hpp"


ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
	std::cout << "ScavTrap " << Name << " was created" << std::endl;
	Hitpoints = 100;
	Energypoints = 50;
	Attackdamage = 20;
}
ScavTrap::~ScavTrap(){std::cout<< "ScavTrap " << Name << " was destroyed" << std::endl;};

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << " ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignment operator called" <<std::endl;
	if (this == &other)
		return (*this);
	this->Name = other.Name;
	this->Hitpoints = other.Hitpoints;
	this->Energypoints = other.Energypoints;
	return (*this);
}
void	ScavTrap::guardGate(void){std::cout<< "ScavTrap " << this->Name << " is in guardGate mode" << std::endl;}


void	ScavTrap::attack(const std::string &target)
{
	if (this->Energypoints > 0 && this->Hitpoints > 0)
	{
		this->Energypoints--;
		std::cout << "ScavTrap " << this->Name << " attacked " << target << " causing " << this->Attackdamage << " points of damage! " << std::endl;
	}
	else if (this->Energypoints <= 0)
		std::cout << "ScavTrap " << this->Name << " has no Energypoints left " << std::endl;
	else if (this->Hitpoints <= 0)
		std::cout << "ScavTrap " << this->Name << " has no Hitpoints left " << std::endl;
}
