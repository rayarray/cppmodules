#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdexcept>
#include <iostream>
#include <string>

struct BureaucratException : std::logic_error
{
	using logic_error::logic_error;
	BureaucratException() : logic_error("Undefined Bureaucrat exception\n") {}
};

class Bureaucrat
{
public:
	// Exceptions
	static BureaucratException GradeTooHighException();
	static BureaucratException GradeTooLowException();
	// Constructors
	Bureaucrat(std::string name, int grade);
	Bureaucrat();
	Bureaucrat(const Bureaucrat &copy);

	// Destructor
	~Bureaucrat();

	// Operators
	Bureaucrat &operator=(const Bureaucrat &assign);

	// Getters / Setters
	std::string getName() const;
	int getGrade() const;
	void upGrade();
	void downGrade();

private:
	const std::string _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &st);

#endif