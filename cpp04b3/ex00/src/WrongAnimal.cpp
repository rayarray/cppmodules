/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:06:57 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/30 14:49:30 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructors

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "\e[0;33mDefault Constructor called of WrongAnimal\e[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	type = copy.type;
	std::cout << "\e[0;33mCopy Constructor called of WrongAnimal\e[0m" << std::endl;
}

// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "\e[0;31mDestructor called of WrongAnimal\e[0m" << std::endl;
}

// Operators
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &assign)
{
	if (this == &assign)
		return *this;
	type = assign.type;
	return *this;
}

// Getters / Setters
const std::string &WrongAnimal::getType() const
{
	return type;
}

// Member functions
void WrongAnimal::makeSound() const
{
	std::cout << "Wrongsilence" << std::endl;
}
