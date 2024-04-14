#include "Intern.hpp"

// Constructors
Intern::Intern()
{
	std::cout << "\e[0;33mDefault Constructor called of Intern\e[0m" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	std::cout << "\e[0;33mCopy Constructor called of Intern\e[0m" << std::endl;
	*this = copy;
}

// Destructor
Intern::~Intern()
{
	std::cout << "\e[0;31mDestructor called of Intern\e[0m" << std::endl;
}

// Operators
Intern &Intern::operator=(const Intern &assign)
{
	if (this == &assign)
		return *this;
	this->~Intern();
	new (this) Intern(assign);
	return *this;
}

// Methods
AForm *makeForm(std::string formName, std::string target)
{
}

// Exceptions
const char *Intern::FormDoesNotExist::what() const throw()
{
	return "Intern exception: Form does not exist\n";
}

// Stream operators
std::ostream &operator<<(std::ostream &stream, const Intern &object)
{
	stream << "std::ostream &out, const Intern &st" << std::endl;
	return stream;
}