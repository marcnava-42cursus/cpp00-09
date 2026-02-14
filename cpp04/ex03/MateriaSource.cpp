#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < kStorageSize; i++)
		m_storage[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	for (int i = 0; i < kStorageSize; i++)
		m_storage[i] = 0;
	*this = other;
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &other)
{
	if (this != &other)
	{
		for (int i = 0; i < kStorageSize; i++)
		{
			delete m_storage[i];
			m_storage[i] = 0;
			if (other.m_storage[i])
				m_storage[i] = other.m_storage[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < kStorageSize; i++)
		delete m_storage[i];
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < kStorageSize; i++)
	{
		if (!m_storage[i])
		{
			m_storage[i] = m->clone();
			delete m;
			return ;
		}
	}
	delete m;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < kStorageSize; i++)
	{
		if (m_storage[i] && m_storage[i]->getType() == type)
			return (m_storage[i]->clone());
	}
	return (0);
}
