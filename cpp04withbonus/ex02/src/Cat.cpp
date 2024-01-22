/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:27:54 by rleskine          #+#    #+#             */
/*   Updated: 2023/12/01 10:07:11 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors
Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "\e[1;33mDefault Constructor called of Cat\e[0m" << std::endl;
}

Cat::Cat(const Cat &copy)
{
	std::cout << "\e[1;33mCopy Constructor called of Cat\e[0m" << std::endl;
	type = copy.type;
	brain = new Brain();
	*brain = *copy.brain;
}

// Destructor
Cat::~Cat()
{
	delete (brain);
	std::cout << "\e[0;33mDestructor called of Cat\e[0m" << std::endl;
}

// Operators
Cat &Cat::operator=(const Cat &assign)
{
	if (this == &assign)
		return *this;
	type = assign.type;
	return *this;
}

// Getters / Setters
const std::string &Cat::getType() const
{
	return type;
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

void Cat::haveIdea(const std::string &idea) const
{
	brain->addIdea(idea);
}

void Cat::mindRead(bool showPointers) const
{
	brain->mindRead(showPointers);
}
