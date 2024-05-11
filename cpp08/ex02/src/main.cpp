#include "MutatedStack.hpp"
#include <iostream>
#include <list>

void printFirstLast(MutatedStack<float> fs) {
	float f = *(fs.begin());
	std::cout << "stack first: " << f << std::endl;
	std::cout << "stack last : " << *(--(fs.end())) << std::endl;
}

template<typename C>
void printContainer(std::string name, const C& container) {
	auto begin = container.rcbegin();
	auto end = container.rcend();
	std::cout << "Printing container [" << name << "] values: {";
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
	std::cout << "fstack size = " << fstack.size() << std::endl;
	std::cout << fstack.top() << std::endl;
	fstack.pop();
	std::cout << fstack.top() << std::endl;
	MutatedStack<float>* ptrstack = new MutatedStack<float>();
	ptrstack->push(5); ptrstack->push(4); ptrstack->push(3); ptrstack->push(2); ptrstack->push(1);
	printContainer("*ptrstack", *ptrstack);
	MutatedStack<float>copyconst(*ptrstack);
	printContainer("copyconst", copyconst);
	delete ptrstack;
	printContainer("copyconst after ptrstack delete", copyconst);
	MutatedStack<float>copyassign;
	copyassign = copyconst;
	printContainer("copyassign", copyassign);
}