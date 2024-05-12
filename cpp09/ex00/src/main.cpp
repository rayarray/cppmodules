#include "BitcoinExchange.hpp"

int main (int ac, char **ag) {
	if (!ac && ag && ac != 2) {
		return (std::cout << "Please provide an input file as argument to process" << std::endl, 0);
	}
	std::string date = "2012-02-29";
	std::string error;
	btc_date key_date;
	if (!BitcoinExchange::checkDate(date, key_date, error))
		std::cout << error << std::endl;
	else
		std::cout << "Valid date: " << date << std::endl;
}