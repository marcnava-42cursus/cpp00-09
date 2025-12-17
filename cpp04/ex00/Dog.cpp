#include "Dog.hpp"

Dog::Dog(void): Animal("Dog"), m_type("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string const &type): Animal(type), m_type(type)
{
	std::cout << "Dog alternative constructor called" << std::endl;
}

Dog::Dog(Dog const &copy): Animal(copy), m_type(copy.m_type)
{
	*this = copy;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog default destructor called" << std::endl;
}

Dog	&Dog::operator=(Dog const &copy)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &copy)
	{
		Animal::operator=(copy);
		this->m_type = copy.m_type;
	}
	return (*this);
}

std::string const	&Dog::getType(void) const
{
	return (this->m_type);
}

void	Dog::setType(const std::string &type)
{
	Animal::setType(type);
	this->m_type = type;
}

void	Dog::makeSound(void) const
{
	std::cout << "BARK!!!!!" << std::endl;
}
