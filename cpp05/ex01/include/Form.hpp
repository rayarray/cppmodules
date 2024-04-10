#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

struct FormException : std::logic_error
{
	using logic_error::logic_error;
	FormException() : logic_error("Undefined Form exception\n") {}
};

class Form
{
public:
	// Exceptions
	FormException GradeTooHighException();
	FormException GradeTooLowException();
	// Constructors
	Form(std::string name, int sign_grade, int exec_grade);
	Form();
	Form(const Form &copy);

	// Destructor
	~Form();

	// Operators
	Form &operator=(const Form &assign);

	// Getters / Setters
	std::string getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool isSigned() const;

	// Methods
	void beSigned(const Bureaucrat &signer);

private:
	const std::string _name;
	int _sign_grade;
	int _exec_grade;
	bool _signed;
};

std::ostream &operator<<(std::ostream &out, const Form &st);

#endif