#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string &name, int grade) : m_name(name)
{
	if (grade > MIN_GRADE_VALUE)
		throw GradeTooLowException("Grade too low");
	if (grade < MAX_GRADE_VALUE)
		throw GradeTooHighException("Grade too high");
	m_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: m_name(other.m_name), m_grade(other.m_grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->m_grade = other.m_grade;
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
}

std::string Bureaucrat::getName(void) const
{
	return m_name;
}

int Bureaucrat::getGrade(void) const
{
	return m_grade;
}

void Bureaucrat::incrementGrade(void)
{
	if (m_grade == MAX_GRADE_VALUE)
		throw GradeTooHighException("Grade already on maximum value");
	m_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (m_grade == MIN_GRADE_VALUE)
		throw GradeTooLowException("Grade already on minimum value");
	m_grade++;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << m_name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << m_name << " couldn't sign " << form.getName() << " because "
			<< e.what() << "." << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << m_name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << m_name << " couldn't execute " << form.getName() << " because "
			<< e.what() << "." << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade();
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
