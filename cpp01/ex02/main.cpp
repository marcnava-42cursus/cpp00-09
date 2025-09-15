#include <string>
#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "String: " << str << std::endl;
	std::cout << "Memory Address" << std::endl;

	std::cout << "Memory of string: " << &str << std::endl;
	std::cout << "Memory of ptr: " << stringPTR << std::endl;
	std::cout << "Memory of ref: " << &stringREF << std::endl;

	std::cout << "Values" << std::endl;
	std::cout << "Value of string: " << str << std::endl;
	std::cout << "Value of ptr: " << *stringPTR << std::endl;
	std::cout << "Value of ref: " << stringREF << std::endl;
}
