#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

struct FormException : std::logic_error
{
	using logic_error::logic_error;
	FormException() : logic_error("Undefined Form exception\n") {}
};

class AForm
{
public:
	// Exceptions
	FormException GradeTooHighException();
	FormException GradeTooLowException();
	// Constructors
	AForm(std::string name, int sign_grade, int exec_grade);
	AForm();

	// Destructor
	virtual ~AForm();

	// Getters / Setters
	virtual std::string getName() const;
	virtual int getSignGrade() const;
	virtual int getExecGrade() const;
	virtual void beSigned(const Bureaucrat &signer);
	virtual void execute(Bureaucrat const &executor) const = 0;

private:
	const std::string _name;
	const int _sign_grade;
	const int _exec_grade;
	bool _signed;
};

std::ostream &operator<<(std::ostream &out, const Form &st);

#endif