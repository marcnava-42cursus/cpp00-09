#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), m_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), m_target(other.m_target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		m_target = other.m_target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

void ShrubberyCreationForm::executeAction(void) const
{
	std::ofstream file((m_target + "_shrubbery").c_str());

	if (!file)
		throw std::runtime_error("Could not create shrubbery file");
	file << "                  \\_/" << std::endl;
	file << "                --(_)--" << std::endl;
	file << "            .'.   / \\" << std::endl;
	file << "           / . \\" << std::endl;
	file << "          |  |. | ,-'-." << std::endl;
	file << "     ,-'-.\\ \\|  /(  .  )" << std::endl;
	file << "    /  .  \\  |, (  \\|   )" << std::endl;
	file << "   |  .|/  |_|_(    |/   )" << std::endl;
	file << "    \\._|,_/  |  '--.|..-'" << std::endl;
	file << " ______|_____|______|______" << std::endl;
}
