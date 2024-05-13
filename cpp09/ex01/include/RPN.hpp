#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <algorithm>

class RPN
{
	private:
		RPN();
		RPN(const RPN &copy);
		~RPN();

		RPN& operator=(const RPN &assign);

	public:
		// static bool checkDate(const std::string str_date, btc_date& key_date, std::string& error);
		// static bool addPrice(const std::string pair, std::string& error);
		static bool checkValidChar(const char c);
		static bool getTwoFromStack(int& one, int& two);
		static bool doOperation(const char c, std::string& error);
		static bool solveEquation(const std::string& eq, int& result, std::string& error);
		
		static std::stack<int> nbr_stack;
};

#endif