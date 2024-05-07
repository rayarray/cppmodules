#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "functions.hpp"

int main() {
	Base *c = new C;
	identify(c);
	delete c;
	C r_c;
	identify(r_c);
	Base *n = nullptr;
	identify(n);
	//identify(*n);
	Base *generated = generate();
	identify(generated);
	identify(*generated);
	delete generated;
}