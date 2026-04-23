#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class ItemNotFoundException : public std::exception
{
	public:
		ItemNotFoundException();
		ItemNotFoundException(const ItemNotFoundException &other);
		ItemNotFoundException	&operator=(const ItemNotFoundException &other);
		virtual ~ItemNotFoundException() throw();
		virtual const char		*what() const throw();
};

template <typename T>
typename T::iterator		easyfind(T &container, int value);

template <typename T>
typename T::const_iterator	easyfind(const T &container, int value);

inline ItemNotFoundException::ItemNotFoundException()
{
}

inline ItemNotFoundException::ItemNotFoundException(
	const ItemNotFoundException &other) : std::exception(other)
{
	(void)other;
}

inline ItemNotFoundException	&ItemNotFoundException::operator=(
	const ItemNotFoundException &other)
{
	(void)other;
	return (*this);
}

inline ItemNotFoundException::~ItemNotFoundException() throw()
{
}

inline const char	*ItemNotFoundException::what() const throw()
{
	return ("item not found");
}

#include "easyfind.tpp"

#endif
