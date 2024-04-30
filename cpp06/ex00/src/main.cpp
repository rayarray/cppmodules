#include "ScalarConverter.hpp"

int main(int ac, char **ag)
{
	(void)ac;
	ScalarConverter::cast(ag[1]);
	float f = std::numeric_limits<float>::infinity();
	f = -f;
	std::cout << f << std::endl;
}