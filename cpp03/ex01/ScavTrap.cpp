#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->m_hp = 100;
	this->m_ep = 50;
	this->m_ad = 20;
	this->m_gate = false;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
	this->m_gate = copy.m_gate;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->m_hp = 100;
	this->m_ep = 50;
	this->m_ad = 20;
	this->m_gate = false;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap assignation operator called" << std::endl;
	this->m_name = src.m_name;
	this->m_hp = src.m_hp;
	this->m_ep = src.m_ep;
	this->m_ad = src.m_ad;
	return *this;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->m_ep != 0 && this->m_hp > 0)
	{
		std::cout << "ScavTrap " << this->m_name << " attacks " << target << ", causing " << this->m_ad << " points of damage!" << std::endl;
		this->m_ep--;
	}
	if (this->m_hp <= 0)
		std::cout << "ScavTrap " << this->m_name << " is death!" << std::endl;
	if (this->m_ep == 0)
		std::cout << "ScavTrap " << this->m_name << " is out of energy!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->m_gate == false)
	{
		this->m_gate = true;
		std::cout << "ScavTrap " << this->m_name << " is now guarding the gate." << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->m_name << " is already guarding the gate." << std::endl;
}

bool const &ScavTrap::getGate(void) const
{
	return this->m_gate;
}

void ScavTrap::setGate(const bool &gate)
{
	this->m_gate = gate;
}
