#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
public:
	// Constructors
	Bureaucrat(std::string name = "faceless", int grade = -1);

	// Destructor
	~Bureaucrat() {}

	// Getters / Setters
	std::string getName() const;
	int getGrade() const;
	void upGrade() const;
	void downGrade() const;

private:
	std::string _name;
	int _grade;
};

#endif