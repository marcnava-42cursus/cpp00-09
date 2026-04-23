#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;

class Form
{
	private:
		const std::string m_name;
		bool m_signed;
		const int m_sign_grade;
		const int m_exec_grade;
	public:
		Form(void);
		Form(std::string name, int sign_grade, int exec_grade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form(void);

		std::string getName() const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(const Bureaucrat &bureaucrat);

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

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif
