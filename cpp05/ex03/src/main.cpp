#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat b001("b001", 1);
	std::cout << b001;
	Bureaucrat b050("b050", 50);
	std::cout << b050;
	Bureaucrat b100("b100", 100);
	std::cout << b100;
	Bureaucrat b150("b150", 150);
	std::cout << b150;
	ShrubberyCreationForm yard("yard");
	std::cout << yard;
	ShrubberyCreationForm defaultshrub;
	b001.executeForm(yard);
	b100.signForm(yard);
	b001.executeForm(yard);
	b150.executeForm(yard);
	b150.signForm(defaultshrub);
	b001.signForm(defaultshrub);
	b100.executeForm(defaultshrub);
	RobotomyRequestForm robotomy;
	std::cout << robotomy;
	b001.signForm(robotomy);
	b001.executeForm(robotomy);
	PresidentialPardonForm joe_exotic("Joe Exotic");
	std::cout << joe_exotic;
	b001.signForm(joe_exotic);
	b001.executeForm(joe_exotic);
	// try
	// {
	// 	std::cout << "Trying to create form with sign grade 0" << std::endl;
	// 	AForm f("invalid", 0, 150);
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << "\e[0;101mCatch!\e[0m " << e.what();
	// }
	// catch (...)
	// {
	// 	std::cout << "Caught exception of undetermined type" << std::endl;
	// }
}