#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {std::cout << "ScavTrap " << name << " was created" << std::endl;}
ScavTrap::~ScavTrap(){std::cout<< "ScavTrap " << Name << " was destroyed" << std::endl;};

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
