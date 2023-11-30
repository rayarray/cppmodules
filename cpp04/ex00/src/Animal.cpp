/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:06:57 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/30 15:24:10 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructors

Animal::Animal() : type("Animal")
{
	std::cout << "\e[1;32mDefault Constructor called of Animal\e[0m" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	type = copy.type;
	std::cout << "\e[1;32mCopy Constructor called of Animal\e[0m" << std::endl;
}

// Destructor
Animal::~Animal()
{
	std::cout << "\e[0;32mDestructor called of Animal\e[0m" << std::endl;
}

// Operators
Animal &Animal::operator=(const Animal &assign)
{
	if (this == &assign)
		return *this;
	type = assign.type;
	return *this;
}

// Getters / Setters
const std::string &Animal::getType() const
{
	return type;
}

// Member functions
void Animal::makeSound() const {}
