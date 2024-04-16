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

	// Operators
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &assign);

	// Methods
	void action() const;
	AForm *clone(std::string target);
};

#endif