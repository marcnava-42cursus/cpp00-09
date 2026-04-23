#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <ostream>
#include <string>

class AForm;

#define MAX_GRADE_VALUE 1
#define MIN_GRADE_VALUE 150

class Bureaucrat
{
	private:
		const std::string m_name;
		int m_grade;

	public:
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat(void);

		std::string getName(void) const;
		int getGrade(void) const;

		void incrementGrade(void);
		void decrementGrade(void);
		void signForm(AForm &form);
		void executeForm(AForm const &form) const;

		class GradeTooHighException : public std::exception
		{
			private:
				std::string m_message;

			public:
				GradeTooHighException(const std::string& message);
				virtual ~GradeTooHighException(void) throw();
				virtual const char* what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			private:
				std::string m_message;

			public:
				GradeTooLowException(const std::string& message);
				virtual ~GradeTooLowException(void) throw();
				virtual const char* what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &other);

#endif
