#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : virtual public AForm
{
public:
	// Constructors
	ShrubberyCreationForm(std::string target);

	// Destructor
	virtual ~ShrubberyCreationForm();

	// Getters / Setters
	virtual std::string getName() const;
	virtual int getSignGrade() const;
	virtual int getExecGrade() const;
	virtual void beSigned(const Bureaucrat &signer);

private:
	const std::string _name;
	const int _sign_grade;
	const int _exec_grade;
	bool _signed;
};

// std::ostream &operator<<(std::ostream &out, const Form &st);

#endif