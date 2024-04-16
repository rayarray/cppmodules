#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : virtual public AForm
{
public:
	// Constructors
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm();

	// Destructor
	virtual ~RobotomyRequestForm();

	// Operators
	RobotomyRequestForm &operator=(const RobotomyRequestForm &assign);

	// Getters / Setters
	void action() const;
	AForm *clone(std::string target);
};

#endif