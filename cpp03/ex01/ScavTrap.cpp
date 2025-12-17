#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap(): ClapTrap()
{
	this->m_hp = 100;
	this->m_ep = 50;
	this->m_ad = 20;
	this->m_gate = false;
	std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
	this->m_gate = copy.m_gate;
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->m_hp = 100;
	this->m_ep = 50;
	this->m_ad = 20;
	this->m_gate = false;
	std::cout << "ScavTrap Constructor for the name " << this->m_name << " called" << std::endl;
}

// Deconstructors
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Deconstructor for " << this->m_name << " called" << std::endl;
}

// Overloaded Operators
ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	this->m_name = src.m_name;
	this->m_hp = src.m_hp;
	this->m_ep = src.m_ep;
	this->m_ad = src.m_ad;
	return *this;
}

// Public Methods
void	ScavTrap::attack(const std::string &target)
{
	if (this->m_ep > 0 && this->m_hp > 0)
	{
		std::cout << "ScavTrap " << this->m_name << " attacks " << target << ", causing " << this->m_ad << " points of damage!" << std::endl;
		this->m_ep--;
	}
	else if (this->m_ep == 0)
		std::cout << "ScavTrap " << this->m_name << " is not able to attack " << target << ", because he has no energy points left." << std::endl;
	else
		std::cout << "ScavTrap " << this->m_name << " is not able to attack " << target << ", because he has not enough hit points." << std::endl;
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
