#include "ScalarConverter.hpp"


int main(int ac, char **ag)
{	
	if (ac < 2)
		std::cout << "Please give a string literal as argument" << std::endl;
	if (ac > 2)
		std::cout << "Too many arguments, please enter only one" << std::endl;
	if (ac != 2)
		return 0;
	ScalarConverter::convert(ag[1]);
}
