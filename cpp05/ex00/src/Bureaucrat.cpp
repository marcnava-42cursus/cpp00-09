#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : m_name(name)
{
	if (grade > 150) throw GradeTooLowException("Grade too low");
	if (grade < 1) throw GradeTooHighException("Grade too high");
	m_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->m_name = other.m_name;
		this->m_grade = other.m_grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
}

std::string Bureaucrat::getName(void) const
{
	return m_name.c_str();
}

int Bureaucrat::getGrade(void) const
{
	return m_grade;
}

void Bureaucrat::incrementGrade(void)
{
	if (m_grade == MAX_GRADE_VALUE) throw GradeTooHighException("Grade already on maximum value");
	m_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (m_grade == MIN_GRADE_VALUE) throw GradeTooLowException("Grade already on minimum value");
	m_grade++;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &other)
{
	os << other.getName() << ", bureaucreat grade " << other.getGrade() << std::endl;
	return os;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& message)
	: m_message(message)
{
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw()
{
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return m_message.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& message)
	: m_message(message)
{
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw()
{
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return m_message.c_str();
}
