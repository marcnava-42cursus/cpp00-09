#include "RPN.hpp"

int main(int argc, char const *argv[])
{
	if (!argv || argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	RPN stack;

	int i = 0;
	while (argv[1][i] != '\0') {
		char cpy = argv[1][i];

		if (std::isdigit(cpy))
			stack.addElement(cpy - '0');
		else {
			try {
				if (cpy == '+')
					stack.sum();
				else if (cpy == '-')
					stack.sub();
				else if (cpy == '*')
					stack.mul();
				else if (cpy == '/')
					stack.div();
				else {
					if (cpy != ' ') {
						std::cerr << "Error" << std::endl;
						return 1;
					}
				}
			}
			catch (std::exception& ex) {
				std::cerr << ex.what() << std::endl;
				return 1;
			}
		}
		i++;
	}
	if (stack.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	std::cout << stack.getElement() << std::endl;
	return 0;
}
