#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
}

ClapTrap::ClapTrap(std::string name): m_name(name), m_hp(10), m_ep(10), m_ad(0)
{
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
	*this = other;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &other)
{
	m_name = other.getName();
	m_hp = other.getHp();
	m_ep = other.getEp();
	m_ad = other.getAd();
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (m_ep != 0 && m_hp > 0)
	{
		std::cout << "ClapTrap " << m_name << " attacks " << target << ", causing " << m_ad << " points of damage!" << std::endl;
		m_ep--;
	}
	if (m_hp <= 0)
		std::cout << "ClapTrap " << m_name << " is death!" << std::endl;
	if (m_ep == 0)
		std::cout << "ClapTrap " << m_name << " is out of energy!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->m_hp > 0)
	{
		std::cout << "ClapTrap " << this->m_name << " took " << amount << " point" << (amount == 1 ? "" : "s") << " of damage!" << std::endl;
		this->m_hp -= amount;
	}
	else
		std::cout << "ClapTrap " << this->m_name << " is already dead!" << std::endl;
	if (this->m_hp < 0)
		this->m_hp = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->m_hp > 0 && this->m_ep)
	{
		std::cout << "ClapTrap " << this->m_name << " healed " << amount << " point(s)." << std::endl;
		this->m_hp += amount;
		this->m_ep--;
	}
	if (this->m_hp <= 0)
		std::cout << "Cannot repair because: ClapTrap " << this->m_name << " is dead." << std::endl;
	else if (!this->m_ep)
		std::cout << "ClapTrap " << this->m_name << " is out of energy points!" << std::endl;
}

std::string const &ClapTrap::getName() const
{
	return m_name;
}

int const &ClapTrap::getHp() const
{
	return m_hp;
}

int const &ClapTrap::getEp() const
{
	return m_ep;
}

int const &ClapTrap::getAd() const
{
	return m_ad;
}

void ClapTrap::setName(const std::string &name)
{
	m_name = name;
}

void ClapTrap::setHp(const int &hp)
{
	m_hp = hp;
}

void ClapTrap::setEp(const int &ep)
{
	m_ep = ep;
}

void ClapTrap::setAd(const int &ad)
{
	m_ad = ad;
}
