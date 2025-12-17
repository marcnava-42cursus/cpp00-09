#include "Fixed.hpp"
#include <cmath>

const int Fixed::m_fractional_bits = 8;

Fixed::Fixed(void) : m_fp_number(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	m_fp_number = number << m_fractional_bits;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	m_fp_number = static_cast<int>(number * (1 << m_fractional_bits));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(other.getRawBits());
	return *this;
}

bool Fixed::operator==(const Fixed &other) const
{
	std::cout << "Equal assignment operator called" << std::endl;
	return this->toFloat() == other.toFloat();
}

bool Fixed::operator!=(const Fixed &other) const
{
	std::cout << "Not equal assignment operator called" << std::endl;
	return this->toFloat() != other.toFloat();
}

bool Fixed::operator>=(const Fixed &other) const
{
	std::cout << "Greater or equal assignment operator called" << std::endl;
	return this->toFloat() >= other.toFloat();
}

bool Fixed::operator<=(const Fixed &other) const
{
	std::cout << "Less or equal assignment operator called" << std::endl;
	return this->toFloat() <= other.toFloat();
}

bool Fixed::operator>(const Fixed &other) const
{
	std::cout << "Greater assignment operator called" << std::endl;
	return this->toFloat() > other.toFloat();
}

bool Fixed::operator<(const Fixed &other) const
{
	std::cout << "Less assignment operator called" << std::endl;
	return this->toFloat() < other.toFloat();
}

Fixed Fixed::operator+(const Fixed &other) const
{
	std::cout << "Addition assignment operator called" << std::endl;
	Fixed result(this->toFloat() + other.toFloat());
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	std::cout << "Substraction assignment operator called" << std::endl;
	Fixed result(this->toFloat() - other.toFloat());
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	std::cout << "Multipllication assignment operator called" << std::endl;
	Fixed result(this->toFloat() * other.toFloat());
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	std::cout << "Division assignment operator called" << std::endl;
	Fixed result(this->toFloat() / other.toFloat());
	return result;
}

Fixed	&Fixed::operator++(void)
{
	std::cout << "Preincrement assignment operator called" << std::endl;
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	std::cout << "Predecrement assignment operator called" << std::endl;
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	std::cout << "Postincrement assignment operator called" << std::endl;
	Fixed tmp = *this;
	this->setRawBits(this->getRawBits() + 1);
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	std::cout << "Postdecrement assignment operator called" << std::endl;
	Fixed tmp = *this;
	this->setRawBits(this->getRawBits() - 1);
	return (tmp);
}

int Fixed::getRawBits() const
{
	std::cout << "Member function operator called" << std::endl;
	return m_fp_number;
}

void Fixed::setRawBits(int const raw)
{
	m_fp_number = raw;
}

int Fixed::toInt(void) const
{
	int result = m_fp_number >> m_fractional_bits;
	return result;
}

float Fixed::toFloat(void) const
{
	float result = static_cast<float>(m_fp_number) / (1 << m_fractional_bits);
	return result;
}

const Fixed	&Fixed::min(Fixed const &f1, Fixed const &f2)
{
	return f1 < f2 ? f1 : f2;
}

const Fixed	&Fixed::max(Fixed const &f1, Fixed const &f2)
{
	return f1 > f2 ? f1 : f2;
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
	
	os << fixed.toFloat();
	return os;
}
