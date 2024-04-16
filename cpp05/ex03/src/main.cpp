#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	ShrubberyCreationForm yard("yard");
	RobotomyRequestForm robotomy;
	PresidentialPardonForm joe_exotic("Joe Exotic");
	Intern temp;
	temp.learnForm("Shrubbery Creation", yard);
	temp.learnForm("Robotomy Request", robotomy);
	temp.learnForm("Presidential Pardon", joe_exotic);
	AForm *intern_test = temp.makeForm("robotomy reQuest", "badrobot");
	std::cout << *intern_test << intern_test->getTarget() << std::endl;
	AForm *intern_test2 = temp.makeForm("boobaa", "not available");
	std::cout << intern_test2 << std::endl;
}