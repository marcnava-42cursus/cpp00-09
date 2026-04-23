#include "Span.hpp"

Span::FullSpanException::FullSpanException()
{
}

Span::FullSpanException::FullSpanException(const FullSpanException &other)
	: std::exception(other)
{
	(void)other;
}

Span::FullSpanException	&Span::FullSpanException::operator=(
	const FullSpanException &other)
{
	(void)other;
	return (*this);
}

Span::FullSpanException::~FullSpanException() throw()
{
}

const char	*Span::FullSpanException::what() const throw()
{
	return ("span is already full");
}

Span::NoSpanFoundException::NoSpanFoundException()
{
}

Span::NoSpanFoundException::NoSpanFoundException(
	const NoSpanFoundException &other) : std::exception(other)
{
	(void)other;
}

Span::NoSpanFoundException	&Span::NoSpanFoundException::operator=(
	const NoSpanFoundException &other)
{
	(void)other;
	return (*this);
}

Span::NoSpanFoundException::~NoSpanFoundException() throw()
{
}

const char	*Span::NoSpanFoundException::what() const throw()
{
	return ("not enough numbers to find a span");
}

Span::Span() : _maxSize(0)
{
}

Span::Span(unsigned int maxSize) : _maxSize(maxSize)
{
}

Span::Span(const Span &other)
{
	*this = other;
}

Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span()
{
}

void	Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw FullSpanException();
	_numbers.push_back(number);
}

unsigned int	Span::shortestSpan() const
{
	std::vector<int>	ordered;
	unsigned int		shortest;
	unsigned int		current;
	std::size_t			i;

	if (_numbers.size() < 2)
		throw NoSpanFoundException();
	ordered = _numbers;
	std::sort(ordered.begin(), ordered.end());
	shortest = std::numeric_limits<unsigned int>::max();
	i = 1;
	while (i < ordered.size())
	{
		current = static_cast<unsigned int>(
				static_cast<long>(ordered[i]) - static_cast<long>(ordered[i - 1]));
		if (current < shortest)
			shortest = current;
		++i;
	}
	return (shortest);
}

unsigned int	Span::longestSpan() const
{
	std::vector<int>::const_iterator	minIt;
	std::vector<int>::const_iterator	maxIt;

	if (_numbers.size() < 2)
		throw NoSpanFoundException();
	minIt = std::min_element(_numbers.begin(), _numbers.end());
	maxIt = std::max_element(_numbers.begin(), _numbers.end());
	return (static_cast<unsigned int>(
		static_cast<long>(*maxIt) - static_cast<long>(*minIt)));
}
