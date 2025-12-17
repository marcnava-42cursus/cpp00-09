#include "DiamondTrap.hpp"

// Constructors
DiamondTrap::DiamondTrap(): ClapTrap("defaultDT_clap_trap"), ScavTrap(), FragTrap()
{
	this->m_name = "defaultDT";
	// DiamondTrap uses FragTrap HP & AD, ScavTrap EP
	this->m_hp = 100;
	this->m_ep = 50;
	this->m_ad = 30;
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_trap"), ScavTrap(name), FragTrap(name)
{
	this->m_name = name;
	// DiamondTrap uses FragTrap HP & AD, ScavTrap EP
	this->m_hp = 100;
	this->m_ep = 50;
	this->m_ad = 30;
	std::cout << "DiamondTrap Constructor for the name " << this->m_name << " called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Deconstructor for " << this->m_name << " called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout << "DiamondTrap Assignation operator called" << std::endl;
	if (this != &src)
	{
		// Copy base parts and own name
		ClapTrap::operator=(src);
		ScavTrap::operator=(src);
		FragTrap::operator=(src);
		this->m_name = src.m_name;
	}
	return *this;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Hello i am a DiamondTrap named " << this->m_name << " and i am originated from the ClapTrap named " << ClapTrap::m_name << "." << std::endl;
}
