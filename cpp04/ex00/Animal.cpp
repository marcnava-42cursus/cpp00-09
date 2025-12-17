#include "Animal.hpp"

Animal::Animal(void): m_type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type): m_type(type)
{
	std::cout << "Animal alternative constructor called" <<std::endl;
}

Animal::Animal(Animal const &other): m_type(other.m_type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal	&Animal::operator=(Animal const &other)
{
	std::cout << "Animal assignment operator called" << std::endl;
	this->setType(other.getType());
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "Animal default destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal made a sound" << std::endl;
}

std::string const &Animal::getType() const
{
	return this->m_type;
}

void Animal::setType(std::string const &type)
{
	this->m_type = type;
}
