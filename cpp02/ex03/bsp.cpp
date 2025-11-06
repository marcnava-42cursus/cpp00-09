#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed area = Fixed::abs((b.getX() - a.getX()) * (c.getY() - a.getY()) - 
							 (c.getX() - a.getX()) * (b.getY() - a.getY())) / 2;
	
	Fixed area1 = Fixed::abs((a.getX() - point.getX()) * (b.getY() - point.getY()) - 
							  (b.getX() - point.getX()) * (a.getY() - point.getY())) / 2;
	
	Fixed area2 = Fixed::abs((b.getX() - point.getX()) * (c.getY() - point.getY()) - 
							  (c.getX() - point.getX()) * (b.getY() - point.getY())) / 2;
	
	Fixed area3 = Fixed::abs((c.getX() - point.getX()) * (a.getY() - point.getY()) - 
							  (a.getX() - point.getX()) * (c.getY() - point.getY())) / 2;
	
	return (area1 > 0 && area2 > 0 && area3 > 0 && area == area1 + area2 + area3);
}