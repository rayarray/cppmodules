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
void Intern::learnForm(AForm &form)
{
	std::cout << typeid(form).name() << " <-typeid quote-> " << quote(form) << std::endl;
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	(void)formName;
	(void)target;
	return nullptr;
}

// Exceptions
const char *Intern::FormDoesNotExist::what() const throw()
{
	return "Intern exception: Form does not exist\n";
}

// Stream operators
std::ostream &operator<<(std::ostream &out, const Intern &st)
{
	(void)st;
	out << "std::ostream &out, const Intern &st" << std::endl;
	return out;
}
