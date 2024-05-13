#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <deque>
# include <algorithm>
# include <type_traits>
# include <utility>

# define I_START 0
# define I_END -1
# define I_OVERFLOW 11

template<typename T = int, typename Container = std::deque<T> >
class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &copy);

	private:
		PmergeMe& operator=(const PmergeMe &assign);

	public:
		PmergeMe<std::pair<T, T>, Container> nextMerge();
		void storeValue(const int value);
		void storeValue(std::pair<T, T> pair);
		bool convertValues(const std::string& values, std::string& error);
		typename Container::iterator getPairValue(typename Container::iterator pair);
		void switchPairs();
		void sortPairs();
		void recursiveSortPairs(typename Container::iterator main_it, typename Container::iterator pend_it);
		void quickSortPairs(typename Container::iterator main_it, typename Container::iterator pend_it);
		//bool makePairs(T *values, const unsigned int size);

		//static bool getTwoFromStack(int& one, int& two);
		//static bool doOperation(const char c, std::string& error);
		//static bool solveEquation(const std::string& eq, int& result, std::string& error);
		
		//std::stack<int> nbr_stack;
		const unsigned int level;
		Container main;
		Container pend;
		typename Container::iterator main_it;
		typename Container::iterator pend_it;
		//PmergeMe<std::pair<T, T>, Container> *next_merge;	
};

#include "PmergeMe.tpp"

#endif