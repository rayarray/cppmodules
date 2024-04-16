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
	for (int i = 0; !_formName[i].empty() && i < MAX_FORMS; i++)
		delete _form[i];
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
bool Intern::learnForm(std::string formName, AForm &form)
{
	// std::cout << typeid(form).name() << " <-typeid " << std::endl;
	for (int i = 0; i < MAX_FORMS; i++)
	{
		if (formName == _formName[i])
			break;
		if (_formName[i].empty())
		{
			_form[i] = form.clone("clone source, do not use");
			_formName[i] = formName;
			return true;
		}
	}
	return false;
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	for (int i = 0; !_formName[i].empty() && i < MAX_FORMS; i++)
	{
		if (strcasecmp(formName.c_str(), _formName[i].c_str()) == 0)
			return (_form[i]->clone(target));
	}
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
