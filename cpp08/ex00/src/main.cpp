#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <iostream>

int main(void) {
	std::cout << "___________vector" << std::endl;
	std::vector<int>int_vec({ -42, 21, 42 });
	int *foundeded = &::easyfind<std::vector<int> >(int_vec, 42);
	std::cout << "easyfind result: " << *foundeded << std::endl;
	std::cout << "changing found value to 84 and repeating easyfind with 42" << std::endl;
	*foundeded = 84;
	try {
		::easyfind<std::vector<int> >(int_vec, 42);
	} catch (std::invalid_argument &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "___________deque" << std::endl;
	std::deque<int>int_deq({ -42, 21, 42});
	int *foundededagain = &::easyfind<std::deque<int> >(int_deq, 42);
	std::cout << "easyfind result: " << *foundededagain << std::endl;
	*foundededagain = 84;
	std::cout << "changing found value to 84 and repeating easyfind with 42" << std::endl;
	try {
		::easyfind<std::deque<int> >(int_deq, 42);
	} catch (std::invalid_argument &e) {
		std::cout << e.what() << std::endl;
	}
}