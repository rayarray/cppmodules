#include "Bureaucrat.hpp"

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

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << std::endl;
	*this = copy;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}

// Operators
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &assign)
{
	if (this == &assign)
		return *this;
	this->~Bureaucrat();
	new (this) Bureaucrat(assign);
	return *this;
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

std::ostream &operator<<(std::ostream &out, const Bureaucrat &st)
{
	out << "Hello, I am " << st.getName()
		<< ", a grade " << st.getGrade()
		<< " bureaucrat." << std::endl;
	return out;
}