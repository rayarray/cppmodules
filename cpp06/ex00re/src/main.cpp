#include "ScalarConverter.hpp"


int main(int ac, char **ag)
{
	if (ac != 2)
		return 0;
	ScalarConverter::convert(ag[1]);
}
