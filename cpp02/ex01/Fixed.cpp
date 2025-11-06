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

int Fixed::getRawBits() const
{
	return m_fp_number;
}

void Fixed::setRawBits(int const raw) { m_fp_number = raw; }

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

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return os;
}
