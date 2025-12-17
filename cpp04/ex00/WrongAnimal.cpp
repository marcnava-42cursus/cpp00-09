#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): m_type("undefined")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string const &type): m_type(type)
{
	std::cout << "WrongAnimal alternative constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
	*this = copy;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal default destructor called" << std::endl;
}

WrongAnimal const	&WrongAnimal::operator=(WrongAnimal const &copy)
{
	std::cout << "WrongAnimal asignment operator called" << std::endl;
	this->m_type = copy.getType();
	return (*this);
}

std::string const	&WrongAnimal::getType(void) const
{
	return (this->m_type);
}

void	WrongAnimal::setType(const std::string &type)
{
	this->m_type = type;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal made a sound!" << std::endl;
}
