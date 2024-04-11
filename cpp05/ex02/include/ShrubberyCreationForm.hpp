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

private:
	Shrub *newShrub(int val) const;
	void insert(Shrub *&root, int val) const;
	void printToFile(Shrub *root, std::ofstream &file) const;
	void freeShrub(Shrub *root) const;
};

#endif