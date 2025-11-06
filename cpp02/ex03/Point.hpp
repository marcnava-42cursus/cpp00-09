#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
	private:
		const Fixed m_x;
		const Fixed m_y;
	public:
		Point(void);

		Point(float x, float y);

		Point(Point const &other);

		Point	&operator=(Point const &other);

		~Point(void);

		const Fixed &getX(void) const;
		const Fixed &getY(void) const;
};

#endif
