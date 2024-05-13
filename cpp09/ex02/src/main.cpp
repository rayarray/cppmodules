#include "PmergeMe.hpp"

int main(int ac, char **ag) {
	if (ac != 2) return (std::cout << "Please provide exactly one argument (hint: use quotes)" << std::endl, 0);
	std::string error;
	PmergeMe pm_deque;
	if (!pm_deque.convertValues(ag[1], error))
		std::cout << "Error: " << error << std::endl;
	pm_deque.switchPairs();
	pm_deque.nextMerge();
	//std::string error;
	//int result;
	//if (!RPN::solveEquation(ag[1], result, error))
	//	std::cout << error << std::endl;
	//else
	//	std::cout << result << std::endl;
	printContainer(pm_deque.main);
	printContainer(pm_deque.pend);
	return 0;
}
