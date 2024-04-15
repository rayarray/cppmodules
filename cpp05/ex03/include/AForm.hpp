#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string _name;
	const std::string _target;
	const int _sign_grade;
	const int _exec_grade;
	bool _signed;

public:
	// __Constructors
	AForm(std::string name, int sign_grade, int exec_grade);
	AForm();
	AForm(std::string name, int sign_grade, int exec_grade, std::string target);
	// __Destructor
	virtual ~AForm();
	// __Getters / Setters
	virtual std::string getName() const;
	virtual std::string getTarget() const;
	virtual int getSignGrade() const;
	virtual int getExecGrade() const;
	virtual bool isSigned() const;
	// __Methods
	virtual void beSigned(const Bureaucrat &signer);
	virtual void execute(Bureaucrat const &executor) const;
	virtual void action() const = 0;
	virtual AForm *clone(std::string target) = 0;

	// __Exceptions
	class GradeTooHighException : public std::runtime_error
	{
	public:
		GradeTooHighException() : std::runtime_error("\e[1;97mForm exception: Signer grade too \e[0;103mhigh\e[0m\n") {}
	};

	class GradeTooLowException : public std::runtime_error
	{
	public:
		GradeTooLowException() : std::runtime_error("\e[1;97mForm exception: Signer grade too \e[0;105mlow\e[0m\n") {}
	};

	class FormNotSignedException : public std::runtime_error
	{
	public:
		FormNotSignedException() : std::runtime_error("\e[1;97mForm exception: Cannot execute, form \e[0;105mnot signed\e[0m\n") {}
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &st);

#endif