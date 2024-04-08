#include "Bureaucrat.hpp"

// Exceptions
std::string Bureaucrat::GradeTooHighException()
{
	return "Grade too high!";
}

std::string Bureaucrat::GradeTooLowException()
{
	return "Grade too low!";
}
// Constructors
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "\e[0;33mFields Constructor called of Bureaucrat\e[0m" << std::endl;
	std::cout << "name: " << name << ", grade: " << grade << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat() : Bureaucrat("faceless", 150) {}
// Bureaucrat::Bureaucrat() {}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}

// Operators
// Bureaucrat &Bureaucrat::operator=(const Bureaucrat &assign)
// {
// 	_name = assign.getName();
// 	_grade = assign.getGrade();
// 	return *this;
// }

// Getters / Setters
std::string Bureaucrat::getName() const
{
	return _name;
}
int Bureaucrat::getGrade() const
{
	return _grade;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &st)
{
	out << "Hello, I am" << st.getName()
		<< ", a grade " << st.getGrade()
		<< " bureaucrat." << std::endl;
	return out;
}