#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iterator>
#include <limits>
#include <vector>

class Span
{
private:
	unsigned int		_maxSize;
	std::vector<int>	_numbers;

public:
	Span();
	Span(unsigned int maxSize);
	Span(const Span &other);
	Span	&operator=(const Span &other);
	~Span();

	void			addNumber(int number);
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;

	template <typename InputIterator>
	void	addRange(InputIterator first, InputIterator last)
	{
		std::vector<int>	buffer;

		for (; first != last; ++first)
			buffer.push_back(*first);
		if (buffer.size() > _maxSize - _numbers.size())
			throw FullSpanException();
		_numbers.insert(_numbers.end(), buffer.begin(), buffer.end());
	}

	class FullSpanException : public std::exception
	{
	public:
		FullSpanException();
		FullSpanException(const FullSpanException &other);
		FullSpanException	&operator=(const FullSpanException &other);
		virtual ~FullSpanException() throw();
		virtual const char	*what() const throw();
	};

	class NoSpanFoundException : public std::exception
	{
	public:
		NoSpanFoundException();
		NoSpanFoundException(const NoSpanFoundException &other);
		NoSpanFoundException	&operator=(const NoSpanFoundException &other);
		virtual ~NoSpanFoundException() throw();
		virtual const char		*what() const throw();
	};
};

#endif
