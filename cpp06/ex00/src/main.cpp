#include "ScalarConverter.hpp"

void sc_cast(std::string);

int main(int ac, char **ag)
{
	(void)ac;
	if (ac != 2)
		return 0;
	sc_cast(ag[1]);
	ScalarConverter::convert(ag[1]);
	float f = std::numeric_limits<float>::infinity();
	f = -f;
	std::cout << f << std::endl;
}