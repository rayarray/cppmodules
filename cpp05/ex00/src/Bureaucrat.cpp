#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "\e[0;33mFields Constructor called of Bureaucrat\e[0m" << std::endl;
	try
	{
	}
	catch
	{
	}
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}

// Operators
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &assign)
{
	_name = assign.getName();
	_grade = assign.getGrade();
	return *this;
}

// Getters / Setters
std::string Bureaucrat::getName() const
{
	return _name;
}
int Bureaucrat::getGrade() const
{
	return _grade;
}
