#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	srand(time(NULL));
	const int abc = rand() % 3;
	if (abc == 0)
		return new A;
	else if (abc == 1)
		return new B;
	else
		return new C;
}

void identify(Base *p) {
	if (p == nullptr) {
		std::cout << "When life gives you null_ptrs, you return" << std::endl;
		return;
	}
	if (A* a_ptr = dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (B* a_ptr = dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (C* a_ptr = dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "unidentified flying object" << std::endl;
}

void identify(Base& p) {
	bool test_a = false, test_b = false, test_c = false;
	try {
		A& _a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)_a;
		return;
	} catch (std::exception &e) {
		test_a = true;
	}
	try {
		B& _b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)_b;
		return;
	} catch (std::exception &e) {
		test_b = true;
	}
	try {
		C& _c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)_c;
		return;
	} catch (std::exception &e) {
		test_c = true;
	}
	if (test_a && test_b && test_c)
		std::cout << "unidentified flying object"  << std::endl;
}
