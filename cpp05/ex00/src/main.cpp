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
	Bureaucrat b("kyro k. kraatti", 125);
}