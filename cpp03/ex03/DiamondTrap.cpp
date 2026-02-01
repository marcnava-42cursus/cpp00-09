#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("defaultDT_clap_trap"), ScavTrap(), FragTrap()
{
	this->m_name = "defaultDT";
	this->m_hp = 100;
	this->m_ep = 50;
	this->m_ad = 30;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_trap"), ScavTrap(name), FragTrap(name)
{
	this->m_name = name;
	this->m_hp = 100;
	this->m_ep = 50;
	this->m_ad = 30;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout << "DiamondTrap assignation operator called" << std::endl;
	if (this != &src)
	{
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

std::string const &DiamondTrap::getName(void) const
{
	return this->m_name;
}

void DiamondTrap::setName(const std::string &name)
{
	this->m_name = name;
}
