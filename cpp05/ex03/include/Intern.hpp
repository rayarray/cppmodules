#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	// Constructors
	Intern();
	Intern(const Intern &copy);

	// Destructor
	~Intern();

	// Operators
	Intern &operator=(const Intern &assign);

	// Methods
	AForm *makeForm(std::string formName, std::string target);

	// Exceptions
	class FormDoesNotExist : public std::exception
	{
		virtual const char *what() const throw();
	};

private:
};

// Stream operators
std::ostream &operator<<(std::ostream &stream, const Intern &object);

#endif