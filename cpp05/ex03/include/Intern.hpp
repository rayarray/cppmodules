#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
// #include "EmptyForm"

#define MAX_FORMS 100

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
	bool learnForm(std::string formName, AForm &form);
	AForm *makeForm(std::string formName, std::string target);

	// Exceptions
	class FormDoesNotExist : public std::exception
	{
		virtual const char *what() const throw();
	};

private:
	AForm *_form[MAX_FORMS];
	std::string _formName[MAX_FORMS];
};

// Stream operators
std::ostream &operator<<(std::ostream &stream, const Intern &object);

#endif