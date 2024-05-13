#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <map>
# include <algorithm>

class BitcoinExchange
{
	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();

		BitcoinExchange& operator=(const BitcoinExchange &assign);

	public:
		//static unsigned int serializeDate(btc_date& date);
		static unsigned int serializeDate(int y, int m, int d);
		static void deserializeDate(const unsigned int &date, int& y, int& m, int& d);
		static bool checkDate(const std::string str_date, unsigned int& key_date, std::string& error);
		static bool addPrice(const std::string pair, std::string& error);
		static bool checkValue(const std::string pair, std::string& error);
		static bool readPricesDBase(std::ifstream& f, std::string& error);
		static bool processValues(std::ifstream& f, std::string& error);
		
	public:
		static std::map<unsigned int, unsigned int> data;
};

#endif