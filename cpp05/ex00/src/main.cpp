#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat("toohigh", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	catch (...)
	{
		std::cout << "Caught exception of undetermined type" << std::endl;
	}
	try
	{
		Bureaucrat("toolow", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	catch (...)
	{
		std::cout << "Caught exception of undetermined type" << std::endl;
	}
	Bureaucrat b("kyro k. kraatti", 125);
	std::cout << b;
	Bureaucrat upgradetest("Top level bureaucrat", 1);
	std::cout << upgradetest;
	try
	{
		upgradetest.upGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	catch (...)
	{
		std::cout << "Caught exception of undetermined type" << std::endl;
	}
	Bureaucrat downgradetest("Bottom level bureaucrat", 150);
	std::cout << downgradetest;
	try
	{
		downgradetest.downGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	catch (...)
	{
		std::cout << "Caught exception of undetermined type" << std::endl;
	}
}