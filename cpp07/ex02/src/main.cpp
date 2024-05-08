#include "Array.hpp"

int main(void) {
	Array<int>a(256);
	a[255] = 42;
	std::cout << a[0] << std::endl;
	std::cout << a[255] << std::endl;
	try {
		std::cout << a[512] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	Array b = a;
	Array c(a);
	try {
		Array<bigData>mem_fail(-1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}