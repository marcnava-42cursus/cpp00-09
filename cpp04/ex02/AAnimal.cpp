#include "AAnimal.hpp"

AAnimal::AAnimal(void): m_type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type): m_type(type)
{
	std::cout << "Animal alternative constructor called" <<std::endl;
}

AAnimal::AAnimal(AAnimal const &other): m_type(other.m_type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

AAnimal	&AAnimal::operator=(AAnimal const &other)
{
	std::cout << "Animal assignment operator called" << std::endl;
	this->setType(other.getType());
	return *this;
}

AAnimal::~AAnimal(void)
{
	std::cout << "Animal default destructor called" << std::endl;
}

void AAnimal::makeSound() const
{
	std::cout << "Animal made a sound" << std::endl;
}

std::string const &AAnimal::getType() const
{
	return this->m_type;
}

void AAnimal::setType(std::string const &type)
{
	this->m_type = type;
}
