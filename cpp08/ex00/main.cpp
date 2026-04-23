#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

static void	testVector()
{
	std::vector<int>	values;
	std::vector<int>::iterator	it;

	values.push_back(10);
	values.push_back(20);
	values.push_back(30);
	it = easyfind(values, 20);
	std::cout << "vector: found " << *it << std::endl;
}

static void	testList()
{
	std::list<int>	values;
	std::list<int>::iterator	it;

	values.push_back(3);
	values.push_back(6);
	values.push_back(9);
	it = easyfind(values, 9);
	std::cout << "list: found " << *it << std::endl;
}

static void	testDequeFailure()
{
	std::deque<int>	values;

	values.push_back(1);
	values.push_back(2);
	values.push_back(3);
	try
	{
		easyfind(values, 99);
	}
	catch (const std::exception &e)
	{
		std::cout << "deque: " << e.what() << std::endl;
	}
}

static void	testConstContainer()
{
	std::vector<int>	tmp;

	tmp.push_back(42);
	tmp.push_back(84);
	const std::vector<int>	values(tmp);
	std::vector<int>::const_iterator	it;

	it = easyfind(values, 42);
	std::cout << "const vector: found " << *it << std::endl;
}

int	main()
{
	try
	{
		testVector();
		testList();
		testDequeFailure();
		testConstContainer();
	}
	catch (const std::exception &e)
	{
		std::cerr << "unexpected error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
