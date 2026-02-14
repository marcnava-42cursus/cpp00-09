#include "Character.hpp"

Character::Character(void) : m_name("unknown")
{
	for (int i = 0; i < kInventorySize; i++)
		m_inventory[i] = 0;
}

Character::Character(std::string const &name) : m_name(name)
{
	for (int i = 0; i < kInventorySize; i++)
		m_inventory[i] = 0;
}

Character::Character(Character const &other) : m_name(other.m_name)
{
	for (int i = 0; i < kInventorySize; i++)
		m_inventory[i] = 0;
	*this = other;
}

Character	&Character::operator=(Character const &other)
{
	if (this != &other)
	{
		m_name = other.m_name;
		for (int i = 0; i < kInventorySize; i++)
		{
			delete m_inventory[i];
			m_inventory[i] = 0;
			if (other.m_inventory[i])
				m_inventory[i] = other.m_inventory[i]->clone();
		}
	}
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < kInventorySize; i++)
		delete m_inventory[i];
}

std::string const	&Character::getName(void) const
{
	return (m_name);
}

void	Character::equip(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < kInventorySize; i++)
	{
		if (!m_inventory[i])
		{
			m_inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= kInventorySize)
		return ;
	m_inventory[idx] = 0;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= kInventorySize)
		return ;
	if (!m_inventory[idx])
		return ;
	m_inventory[idx]->use(target);
}
