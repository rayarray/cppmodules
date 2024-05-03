#include "ScalarConverter.hpp"

void sc_cast(std::string);

// bool isLosslessConversion(const std::string &str, double num)
// {
// 	std::string converted_str = std::to_string()
// }

int main(int ac, char **ag)
{
	(void)ac;
	if (ac != 2)
		return 0;
	// sc_cast(ag[1]);
	ScalarConverter::convert(ag[1]);
	float f = std::numeric_limits<float>::infinity();
	f = -f;
	// std::cout << f << std::endl;
	double num;
	long double lnum;
	try
	{
		num = std::stod(ag[1]);
	}
	catch (const std::exception &e)
	{
		std::cout << "caught exception trying std::stod(): " << e.what() << std::endl;
	}
	try
	{
		lnum = std::stod(ag[1]);
	}
	catch (const std::exception &e)
	{
		std::cout << "caught exception trying std::stod(): " << e.what() << std::endl;
	}
	std::string str_num = std::to_string(num);
	std::string str_lnum = std::to_string(lnum);
	std::cout << "str_lnum: [" << str_lnum << "]" << std::endl;
	std::cout << " str_num: [" << str_num << "]" << std::endl;
}