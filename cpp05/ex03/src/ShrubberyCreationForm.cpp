#include <fstream>
#include "ShrubberyCreationForm.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm()
	: ShrubberyCreationForm("undefined target") {}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Methods
void ShrubberyCreationForm::action() const
{
	std::string filename = getTarget() + "_shrubbery";
	std::ofstream file(filename);
	if (!file)
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}
	file << " ^ /\\   ^\n";
	file << "       / \\  ^\n";
	file.close();
}