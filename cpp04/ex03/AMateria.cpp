#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(void) : m_type("unknown")
{
}

AMateria::AMateria(std::string const &type) : m_type(type)
{
}

AMateria::AMateria(AMateria const &other) : m_type(other.m_type)
{
}

AMateria	&AMateria::operator=(AMateria const &other)
{
	(void)other;
	return (*this);
}

AMateria::~AMateria(void)
{
}

std::string const	&AMateria::getType(void) const
{
	return (m_type);
}

void	AMateria::use(ICharacter &target)
{
	(void)target;
}
