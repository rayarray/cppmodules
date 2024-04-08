#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat : public std::exception
{
public:
	// Exceptions
	static std::string GradeTooHighException();
	static std::string GradeTooLowException();
	// Constructors
	Bureaucrat(std::string name, int grade);
	Bureaucrat();

	// Destructor
	~Bureaucrat();

	// Getters / Setters
	std::string getName() const;
	int getGrade() const;
	void upGrade() const;
	void downGrade() const;

private:
	const std::string _name;
	int _grade;
};

#endif