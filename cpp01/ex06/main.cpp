#include "Harl.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
		return (std::cout << "Invalid number of arguments" << std::endl, 0);

	Harl harl;
	harl.complain(argv[1]);
	return 0;
}
