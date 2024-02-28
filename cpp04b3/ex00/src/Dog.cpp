/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:27:54 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/30 15:24:01 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors
Dog::Dog()
{
	type = "Dog";
	std::cout << "\e[1;34mDefault Constructor called of Dog\e[0m" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	type = copy.type;
	std::cout << "\e[1;34mCopy Constructor called of Dog\e[0m" << std::endl;
}

// Destructor
Dog::~Dog()
{
	std::cout << "\e[0;34mDestructor called of Dog\e[0m" << std::endl;
}

// Operators
Dog &Dog::operator=(const Dog &assign)
{
	if (this == &assign)
		return *this;
	type = assign.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Bark!" << std::endl;
}
