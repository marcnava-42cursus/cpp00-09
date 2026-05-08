#include "RPN.hpp"

int main(int argc, char const *argv[])
{
	if (!argv || argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	RPN stack;

	int i = 0;
	while (argv[1][i] != '\0') {
		char cpy = argv[1][i];
		int n1, n2;

		if (std::isdigit(cpy))
			stack.addElement(cpy - '0');
		else {
			if (cpy == '+') {
				if (stack.size() >= 2) {
					n1 = stack.getElement();
					n2 = stack.getElement();
					stack.addElement(n1 + n2);
				}
				else
					return ((std::cerr << "Error" << std::endl), 1);
			}
			else if (cpy == '-') {
				if (stack.size() >= 2) {
					n1 = stack.getElement();
					n2 = stack.getElement();
					stack.addElement(n2 - n1);
				}
				else
					return ((std::cerr << "Error" << std::endl), 1);
			}
			else if (cpy == '*') {
				if (stack.size() >= 2) {
					n1 = stack.getElement();
					n2 = stack.getElement();
					stack.addElement(n1 * n2);
				}
				else
					return ((std::cerr << "Error" << std::endl), 1);
			}
			else if (cpy == '/') {
				if (stack.size() >= 2 || n1 != 0) {
					n1 = stack.getElement();
					n2 = stack.getElement();
					stack.addElement(n2 / n1);
				}
				else
					return ((std::cerr << "Error" << std::endl), 1);
			}
			else {
				if (cpy == ' ')
					continue;
				std::cerr << "Error" << std::endl;
				return 1;
			}
		}
		i++;
	}
	std::cout << stack.getElement() << std::endl;
	return 0;
}
