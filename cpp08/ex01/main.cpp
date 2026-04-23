#include <iostream>
#include <list>
#include <vector>

#include "Span.hpp"

static void	printSubjectTest()
{
	Span	sp(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "subject shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "subject longest: " << sp.longestSpan() << std::endl;
}

static void	printFullSpanTest()
{
	Span	sp(2);

	sp.addNumber(1);
	sp.addNumber(2);
	try
	{
		sp.addNumber(3);
	}
	catch (const std::exception &e)
	{
		std::cout << "full span: " << e.what() << std::endl;
	}
}

static void	printNoSpanTest()
{
	Span	sp(3);

	sp.addNumber(42);
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "single element: " << e.what() << std::endl;
	}
}

static void	printRangeTest()
{
	Span			sp(6);
	std::list<int>	values;

	values.push_back(10);
	values.push_back(30);
	values.push_back(20);
	values.push_back(18);
	sp.addRange(values.begin(), values.end());
	std::cout << "range shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "range longest: " << sp.longestSpan() << std::endl;
}

static void	printLargeTest()
{
	Span				sp(10000);
	std::vector<int>		values;
	int					i;

	i = 0;
	while (i < 10000)
	{
		values.push_back(i * 3);
		++i;
	}
	sp.addRange(values.begin(), values.end());
	std::cout << "large shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "large longest: " << sp.longestSpan() << std::endl;
}

static void	printOverflowRangeTest()
{
	Span				sp(3);
	std::vector<int>	values;

	values.push_back(1);
	values.push_back(2);
	values.push_back(3);
	values.push_back(4);
	try
	{
		sp.addRange(values.begin(), values.end());
	}
	catch (const std::exception &e)
	{
		std::cout << "range overflow: " << e.what() << std::endl;
	}
}

int	main()
{
	printSubjectTest();
	printFullSpanTest();
	printNoSpanTest();
	printRangeTest();
	printLargeTest();
	printOverflowRangeTest();
	return (0);
}
