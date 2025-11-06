#include "Fixed.hpp"
#include <cmath>

const int Fixed::m_fractional_bits = 8;

Fixed::Fixed(void) : m_fp_number(0)
{
}

Fixed::Fixed(const int number)
{
	m_fp_number = number << m_fractional_bits;
}

Fixed::Fixed(const float number)
{
	m_fp_number = static_cast<int>(number * (1 << m_fractional_bits));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(other.getRawBits());
	return *this;
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->toFloat() == other.toFloat();
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->toFloat() != other.toFloat();
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->toFloat() >= other.toFloat();
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->toFloat() <= other.toFloat();
}

bool Fixed::operator>(const Fixed &other) const
{
	return this->toFloat() > other.toFloat();
}

bool Fixed::operator<(const Fixed &other) const
{
	return this->toFloat() < other.toFloat();
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result(this->toFloat() + other.toFloat());
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result(this->toFloat() - other.toFloat());
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result(this->toFloat() * other.toFloat());
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result(this->toFloat() / other.toFloat());
	return result;
}

Fixed	&Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->setRawBits(this->getRawBits() + 1);
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->setRawBits(this->getRawBits() - 1);
	return (tmp);
}

int Fixed::getRawBits() const
{
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

Fixed	Fixed::abs(Fixed const &f)
{
	if (f.toFloat() < 0)
		return Fixed(f.toFloat() * -1);
	return Fixed(f.toFloat());
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return os;
}
