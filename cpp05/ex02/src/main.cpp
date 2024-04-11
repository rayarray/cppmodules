#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat b001("b001", 1);
	std::cout << b001;
	Bureaucrat b100("b100", 100);
	std::cout << b100;
	Bureaucrat b150("b150", 150);
	std::cout << b150;
	ShrubberyCreationForm yard("yard");
	std::cout << yard;
	b100.signForm(yard);
	b001.executeForm(yard);
	b150.executeForm(yard);
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