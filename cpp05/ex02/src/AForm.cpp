#include "AForm.hpp"

// Constructors
AForm::AForm(std::string name, int sign_grade, int exec_grade)
	: _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade), _signed(false)
{
	std::cout << "\e[0;33mFields Constructor called of \e[4;37mForm\e[0m" << std::endl;
	if (sign_grade < 1 || exec_grade < 1)
		throw AForm::GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm() : AForm("Standard Form", 150, 150) {}

AForm::AForm(std::string name, int sign_grade, int exec_grade, std::string target)
	: _name(name), _target(target), _sign_grade(sign_grade),
	  _exec_grade(exec_grade), _signed(false) {}

// Destructor
AForm::~AForm()
{
	std::cout << "\e[0;31mDestructor called of \e[4;37mForm\e[0m" << std::endl;
}

// Getters / Setters
std::string AForm::getName() const { return _name; }
std::string AForm::getTarget() const { return _target; }
int AForm::getSignGrade() const { return _sign_grade; }
int AForm::getExecGrade() const { return _exec_grade; }
bool AForm::isSigned() const { return _signed; }

// Methods
void AForm::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > _sign_grade)
		throw AForm::GradeTooLowException();
	_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->isSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > _exec_grade)
		throw AForm::GradeTooLowException();
	this->action();
}

// Operators
std::ostream &operator<<(std::ostream &out, const AForm &st)
{
	out << "This is a " << st.getName()
		<< " form that requires a grade of " << st.getSignGrade()
		<< " to sign and a grade of " << st.getExecGrade()
		<< " to execute" << std::endl;
	return out;
}