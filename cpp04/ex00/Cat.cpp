#include "Cat.hpp"

Cat::Cat(void): Animal("Cat"), m_type("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string const &type): Animal(type), m_type(type)
{
	std::cout << "Cat alternativa constructor called" << std::endl;
}

Cat::Cat(Cat const &copy): Animal(copy), m_type(copy.m_type)
{
	*this = copy;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat default destructor called" << std::endl;
}

Cat	&Cat::operator=(Cat const &copy)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &copy)
	{
		Animal::operator=(copy);
		this->m_type = copy.m_type;
	}
	return (*this);
}

std::string const	&Cat::getType(void) const
{
	return (this->m_type);
}

void	Cat::setType(const std::string &type)
{
	Animal::setType(type);
	this->m_type = type;
}

void	Cat::makeSound(void) const
{
	std::cout << "MEOW!!!!!" << std::endl;
}
