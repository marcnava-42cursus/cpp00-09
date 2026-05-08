#include "RPN.hpp"

RPN::RPN(void)
{
	addElement(0);
}

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this->getData() != other.getData())
		this->_data = other._data;
	return *this;
}

RPN::~RPN(void)
{
}

const std::stack<int>& RPN::getData(void) const
{
	return _data;
}

void RPN::addElement(int number)
{
	_data.push(number);
}

int RPN::getElement(void)
{
	_data.pop();
}

std::ostream& operator<<(std::ostream& os, const RPN& obj)
{
	(void)obj;
	return os;
}
