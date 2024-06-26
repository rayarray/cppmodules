#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : virtual public AForm
{
public:
	// Constructors
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm();

	// Destructor
	virtual ~PresidentialPardonForm();

	// Operators
	PresidentialPardonForm &operator=(const PresidentialPardonForm &assign);

	// Getters / Setters
	void action() const;
	AForm *clone(std::string target);
};

#endif