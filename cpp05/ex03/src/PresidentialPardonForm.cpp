#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm()
	: PresidentialPardonForm("undefined target") {}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// Methods
void PresidentialPardonForm::action() const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

AForm *PresidentialPardonForm::clone(std::string target)
{
	return new PresidentialPardonForm(target);
}