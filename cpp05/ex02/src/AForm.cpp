#include "AForm.hpp"

// Exceptions
FormException AForm::GradeTooHighException()
{
	return FormException("\e[1;97mForm exception: Signer grade too \e[0;103mhigh\e[0m\n");
}

FormException AForm::GradeTooLowException()
{
	return FormException("\e[1;97mForm exception: Signer grade too \e[0;105mlow\e[0m\n");
}

// Constructors
AForm::AForm(std::string name, int sign_grade, int exec_grade) : _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade), _signed(false)
{
	std::cout << "\e[0;33mFields Constructor called of \e[4;37mForm\e[0m" << std::endl;
	if (sign_grade < 1 || exec_grade < 1)
		throw Form::GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
}

AForm::Form() : AForm("Standard Form", 150, 150) {}

// Destructor
AForm::~Form()
{
	std::cout << "\e[0;31mDestructor called of \e[4;37mForm\e[0m" << std::endl;
}

// Getters / Setters
std::string AForm::getName() const { return _name; }
int AForm::getSignGrade() const { return _sign_grade; }
int AForm::getExecGrade() const { return _exec_grade; }

void AForm::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > _sign_grade)
		throw Form::GradeTooLowException();
	_signed = true;
}

std::ostream &operator<<(std::ostream &out, const Form &st)
{
	out << "This is a " << st.getName()
		<< " form that requires a grade of " << st.getSignGrade()
		<< " to sign and a grade of " << st.getExecGrade()
		<< " to execute" << std::endl;
	return out;
}