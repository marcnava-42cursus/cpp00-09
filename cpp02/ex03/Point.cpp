#include "Point.hpp"

Point::Point(void): m_x(0), m_y(0)
{
}

Point::Point(const float x, const float y): m_x(x), m_y(y)
{
}

Point::Point(Point const &other): m_x(other.getX()), m_y(other.getY())
{
}

Point	&Point::operator=(Point const &other)
{
	(void)other;
	return (*this);
}

Point::~Point(void)
{
}

const Fixed &Point::getX() const
{
	return m_x;
}

const Fixed &Point::getY() const
{
	return m_y;
}