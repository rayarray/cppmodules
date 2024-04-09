#include "Bureaucrat.hpp"
#include "Form.hpp"

// Exceptions
BureaucratException Bureaucrat::GradeTooHighException()
{
	return BureaucratException("\e[1;97mBureaucrat exception: Grade too high\e[0m\n");
}

BureaucratException Bureaucrat::GradeTooLowException()
{
	return BureaucratException("\e[1;97mBureaucrat exception: Grade too low\e[0m\n");
}
// Constructors
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "\e[0;33mFields Constructor called of Bureaucrat\e[0m" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat() : Bureaucrat("faceless", 150) {}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}

// Getters / Setters
std::string Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::upGrade()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade++;
}

void Bureaucrat::downGrade()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade--;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what();
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &st)
{
	out << "Hello, I am " << st.getName()
		<< ", a grade " << st.getGrade()
		<< " bureaucrat." << std::endl;
	return out;
}