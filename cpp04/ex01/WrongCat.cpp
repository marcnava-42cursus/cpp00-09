#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string const &type):WrongAnimal(type)
{
	std::cout << "WrongCat alternative constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy): WrongAnimal(copy)
{
	*this = copy;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat default destructor called" << std::endl;
}

WrongCat const	&WrongCat::operator=(WrongCat const &copy)
{
	std::cout << "WrongCat asignment operator called" << std::endl;
	WrongAnimal::operator=(copy);
	return (*this);
}

std::string const	&WrongCat::getType(void) const
{
	return (this->m_type);
}

void	WrongCat::setType(const std::string &type)
{
	this->m_type = type;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat MEOW!!" << std::endl;
}
