#include "MutatedStack.hpp"
#include <iostream>

void printFirstLast(MutatedStack<float> fs) {
	float f = *(fs.begin());
	std::cout << "stack first: " << f << std::endl;
	std::cout << "stack last : " << *(--(fs.end())) << std::endl;
	//std::cout << "stack last : " << *fs.cend() << std::endl;
}

template<class C, typename I>
void printContainer(C container) {
	I begin = container.cbegin();
	I end = container.cend();
	std::cout << "Printing container values: {";
	while (begin != end) {
		std::cout << *(begin++) << " ";
	}
	std::cout << "}" << std::endl;
}

int main(void) {
	MutatedStack<float> fstack;
	std::cout << std::boolalpha << "fstack is empty = " << fstack.empty() << std::endl;
	fstack.push(42.21f);
	fstack.push(21.42f);
	printFirstLast(fstack);
	//fstack.begin();
	std::cout << "fstack size = " << fstack.size() << std::endl;
	std::cout << fstack.top() << std::endl;
	fstack.pop();
	std::cout << fstack.top() << std::endl;

	MutatedStack<float>* ptrstack = new MutatedStack<float>();
	ptrstack->push(5); ptrstack->push(4); ptrstack->push(3); ptrstack->push(2); ptrstack->push(2);
	printContainer(ptrstack);
	MutatedStack<float>copyconst(*ptrstack);
	printContainer(copyconst);
}