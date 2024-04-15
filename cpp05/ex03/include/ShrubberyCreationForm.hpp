#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

// Define the structure for the individual shrubs
struct Shrub
{
	int val;
	Shrub *left;
	Shrub *right;
};

class ShrubberyCreationForm : virtual public AForm
{
public:
	// Constructors
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm();

	// Destructor
	virtual ~ShrubberyCreationForm();

	// Getters / Setters
	// virtual std::string getName() const;
	// virtual int getSignGrade() const;
	// virtual int getExecGrade() const;
	// virtual void beSigned(const Bureaucrat &signer);
	void action() const;
	AForm *clone(std::string target);
};

#endif