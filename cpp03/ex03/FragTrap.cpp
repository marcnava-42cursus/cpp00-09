#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->m_hp = 100;
	this->m_ep = 100;
	this->m_ad = 30;
	std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->m_hp = 100;
	this->m_ep = 100;
	this->m_ad = 30;
	std::cout << "FragTrap Constructor for the name " << this->m_name << " called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Deconstructor for " << this->m_name << " called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << "FragTrap Assignation operator called" << std::endl;
	this->m_name = src.m_name;
	this->m_hp = src.m_hp;
	this->m_ep = src.m_ep;
	this->m_ad = src.m_ad;
	return *this;
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << this->m_name << ": High Five Guys!!!" << std::endl;
}
