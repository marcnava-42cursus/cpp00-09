#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>

class RPN
{
	private:
		std::stack<int> _data;
	public:
		RPN(void);
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN(void);

		const std::stack<int>& getData(void) const;
		void addElement(int);
		int getElement();
		int size(void) const;
};

std::ostream& operator<<(std::ostream& os, const RPN& obj);

#endif
