#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): Hitpoints(10), Energypoints(10), Attackdamage(0), Name("unknown"){std::cout << "default ClapTrap constructor called" << std::endl;};
ClapTrap::ClapTrap(std::string name) : Hitpoints(10), Energypoints(10), Attackdamage(0), Name(name) {std::cout << "ClapTrap " << Name << " was created" << std::endl;};
ClapTrap::~ClapTrap(){std::cout<< "ClapTrap " << Name << " was destroyed" << std::endl;};

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << " ClapTrap copy assignment operator called" <<std::endl;
	if (this == &other)
		return (*this);
	this->Name = other.Name;
	this->Hitpoints = other.Hitpoints;
	this->Energypoints = other.Energypoints;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->Energypoints <= 0)
		std::cout << "ClapTrap " << this->Name << " has no Energypoints left " << std::endl;
	else if (this->Hitpoints <= 0)
		std::cout << "ClapTrap " << this->Name << " has no Hitpoints left " << std::endl;
	else
	{
		this->Energypoints--;
		std::cout << "ClapTrap " << this->Name << " attacked " << target << " causing " << this->Attackdamage << " points of damage! " << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->Hitpoints == 0)
		std::cout << "ClapTrap " << this->Name << " has no Hitpoints left" << std::endl;
	else
	{
		this->Hitpoints -= amount;
		std::cout << "ClapTrap " << this->Name << " took damage and now has " << this->Hitpoints << " hitpoints left " << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->Energypoints > 0)
	{
		this->Hitpoints += amount;
		this->Energypoints--;
		std::cout << "ClapTrap " << this->Name << " repaired itself and received " << amount << " hitpoints. Total = " << this->Hitpoints << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->Name << " has no Energypoints left " << std::endl;
}
