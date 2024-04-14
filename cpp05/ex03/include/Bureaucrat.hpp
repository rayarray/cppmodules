#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdexcept>
#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
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

	// Methods
	void upGrade();
	void downGrade();
	void signForm(AForm &form);
	void executeForm(AForm const &form);

	// __Exceptions
	class GradeTooHighException : public std::runtime_error
	{
	public:
		GradeTooHighException()
			: std::runtime_error("\e[1;97mBureaucrat exception: Grade too high\e[0m\n") {}
	};
	class GradeTooLowException : public std::runtime_error
	{
	public:
		GradeTooLowException()
			: std::runtime_error("\e[1;97mBureaucrat exception: Grade too low\e[0m\n") {}
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &st);

#endif