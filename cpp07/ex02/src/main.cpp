#include "Array.hpp"

struct bigData {
	long double hog[16384];
};

int main(void) {
	{	std::cout << "\e[0;107m\e[1;90m_____create and index tests\e[0m" << std::endl;
		Array<int>a(256);
		a[0] = -21;
		a[128] = 438274;
		a[255] = 42;
		std::cout << "elem at first index of a:" << a[0] << std::endl;
		std::cout << "elem at last index of a: " <<a[255] << std::endl;
		try {
			std::cout << a[512] << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
	}	}
	try {
		std::cout << "\e[0;107m\e[1;90m_________too large alloc\e[0m" << std::endl;
		Array<bigData>mem_fail(-1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	{	std::cout << "\e[0;107m\e[1;90m____________copy tests\e[0m" << std::endl;
		Array<int> *a = new Array<int>(3); (*a)[0] = -42; (*a)[1] = 21; (*a)[2] = 42;
		std::cout << "a[0]:" << (*a)[0] << " a[1]:" << (*a)[1] << " a[2]:" << (*a)[2] << std::endl;
		Array<int>b(*a);
		std::cout << "b[0]:" << b[0] << " b[1]:" << b[1] << " b[2]:" << b[2] << std::endl;
		delete a;
		std::cout << "b[0]:" << b[0] << " b[1]:" << b[1] << " b[2]:" << b[2] << std::endl;
		Array<int>c;
		c = b;
		std::cout << "c[0]:" << c[0] << " c[1]:" << c[1] << " c[2]:" << c[2] << std::endl;
		std::cout << "\e[0;107m\e[1;90m_________________a little extra\e[0m" << std::endl;
	}
	{	Array<Array<int> >a(3);

		a[0] = Array<int>(3);
		a[0][0] = 42;
		std::cout << "a[0][0]:" << a[0][0] << std::endl;
}	}