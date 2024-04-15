#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm()
	: RobotomyRequestForm("undefined target") {}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// Methods
void RobotomyRequestForm::action() const
{
	srand(reinterpret_cast<uintptr_t>(this));
	const bool success = rand() & 1;

	std::cout << "*drill noises*" << std::endl;
	if (success)
		std::cout << "Dr Roboman has successfully robotomized his patient " << this->getTarget() << std::endl;
	else
		std::cout << "Robotomy attempt at " << this->getTarget() << " has failed!" << std::endl;
}

AForm *RobotomyRequestForm::clone(std::string target)
{
	return new RobotomyRequestForm(target);
}