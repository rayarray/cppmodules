#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <map>
# include <algorithm>

struct btc_date {
	int	y;
	int m;
	int d;
};

struct btc_amount {
	int coins;
	int satoshis;
};

class BitcoinExchange
{
	private:
		// Constructors
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		
		// Destructor
		~BitcoinExchange();
		
		// Operators
		BitcoinExchange& operator=(const BitcoinExchange &assign);

	public:
		static bool checkDate(std::string str_date, btc_date& key_date, std::string& error);
		bool addData(std::string pair, std::string& error);
		
	private:
		std::map<btc_date, float> data;
		std::map<btc_date, btc_amount> input;
};

#endif