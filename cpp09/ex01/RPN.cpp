#include "RPN.hpp"

RPN::RPN(void) { }

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this->getData() == other.getData())
		return *this;
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
	int value;
	if (!_data.empty())
	{
		value = _data.top();
		_data.pop();
	}
	else
		value = 0;
	return (value);
}

int RPN::size(void) const
{
	return _data.size();
}

void RPN::sum(void) {
	int n1, n2;
	if (this->_data.size() >= 2) {
		n1 = this->getElement();
		n2 = this->getElement();
		this->addElement(n1 + n2);
	}
	else
		throw std::runtime_error("Error");
}

void RPN::sub(void) {
	int n1, n2;
	if (this->_data.size() >= 2) {
		n1 = this->getElement();
		n2 = this->getElement();
		this->addElement(n2 - n1);
	}
	else
		throw std::runtime_error("Error");
}

void RPN::mul(void) {
	int n1, n2;
	if (this->_data.size() >= 2) {
		n1 = this->getElement();
		n2 = this->getElement();
		this->addElement(n1 * n2);
	}
	else
		throw std::runtime_error("Error");
}

void RPN::div(void) {
	int n1, n2;
	if (this->_data.size() >= 2) {
		n1 = this->getElement();
		n2 = this->getElement();
		if (n1 == 0)
			throw std::runtime_error("Error");
		this->addElement(n2 / n1);
	}
	else
		throw std::runtime_error("Error");
}

std::ostream& operator<<(std::ostream& os, const RPN& obj)
{
	(void)obj;
	return os;
}
