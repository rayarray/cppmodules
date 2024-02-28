/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:27:54 by rleskine          #+#    #+#             */
/*   Updated: 2024/01/25 13:12:46 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors
Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "\e[1;34mDefault Constructor called of Dog\e[0m" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	std::cout << "\e[1;34mCopy Constructor called of Dog\e[0m" << std::endl;
	type = copy.type;
	brain = new Brain(*copy.brain);
}

// Destructor
Dog::~Dog()
{
	delete (brain);
	std::cout << "\e[0;34mDestructor called of Dog\e[0m" << std::endl;
}

// Operators
Dog &Dog::operator=(const Dog &assign)
{
	if (this == &assign)
		return *this;
	type = assign.type;
	delete this->brain;
	this->brain = new Brain(*assign.brain);
	return *this;
}

// Getters / Setters
const std::string &Dog::getType() const
{
	return type;
}

void Dog::makeSound() const
{
	std::cout << "Bark!" << std::endl;
}

void Dog::haveIdea(const std::string &idea) const
{
	brain->addIdea(idea);
}

void Dog::mindRead(bool showPointers) const
{
	brain->mindRead(showPointers);
}
