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
	Form f001x150("f001x150", 1, 150);
	std::cout << f001x150;
	Form f150x001("f150x001", 150, 1);
	std::cout << f150x001;
	Form f100x100("f100x100", 100, 100);
	std::cout << f100x100;
	try
	{
		std::cout << "Trying to create form with sign grade 0" << std::endl;
		Form f("invalid", 0, 150);
	}
	catch (std::exception &e)
	{
		std::cout << "\e[0;101mCatch!\e[0m " << e.what();
	}
	catch (...)
	{
		std::cout << "Caught exception of undetermined type" << std::endl;
	}
	try
	{
		std::cout << "Trying to create form with exec grade 151" << std::endl;
		Form f("invalid", 1, 151);
	}
	catch (std::exception &e)
	{
		std::cout << "\e[0;101mCatch!\e[0m " << e.what();
	}
	catch (...)
	{
		std::cout << "Caught exception of undetermined type" << std::endl;
	}
	std::cout << "Signing a form f100x100 with b100" << std::endl;
	b100.signForm(f100x100);
	try
	{
		std::cout << "Trying to sign form with not high enough grade" << std::endl;
		f001x150.beSigned(b100);
	}
	catch (std::exception &e)
	{
		std::cout << "\e[0;101mCatch!\e[0m " << e.what();
	}
	catch (...)
	{
		std::cout << "Caught exception of undetermined type" << std::endl;
	}
	std::cout << "Signing a form f001x150 with b100 (should not succeed)" << std::endl;
	b100.signForm(f001x150);
}