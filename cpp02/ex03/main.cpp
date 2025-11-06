#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 10.0f);

	std::cout << "Triangle vertices: A(0,0), B(10,0), C(5,10)" << std::endl << std::endl;

	// Test point inside triangle
	Point p1(5.0f, 5.0f);
	std::cout << "Point (5, 5): " << (bsp(a, b, c, p1) ? "Inside" : "Outside") << std::endl;

	// Test point outside triangle
	Point p2(15.0f, 5.0f);
	std::cout << "Point (15, 5): " << (bsp(a, b, c, p2) ? "Inside" : "Outside") << std::endl;

	// Test point on vertex
	Point p3(0.0f, 0.0f);
	std::cout << "Point (0, 0) [vertex]: " << (bsp(a, b, c, p3) ? "Inside" : "Outside") << std::endl;

	// Test point on edge
	Point p4(5.0f, 0.0f);
	std::cout << "Point (5, 0) [edge]: " << (bsp(a, b, c, p4) ? "Inside" : "Outside") << std::endl;

	// Test another point inside
	Point p5(6.0f, 4.0f);
	std::cout << "Point (6, 4): " << (bsp(a, b, c, p5) ? "Inside" : "Outside") << std::endl;

	// Test point outside
	Point p6(0.0f, 15.0f);
	std::cout << "Point (0, 15): " << (bsp(a, b, c, p6) ? "Inside" : "Outside") << std::endl;

	return 0;
}
