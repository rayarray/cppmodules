/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:27:54 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/30 15:24:25 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors
Cat::Cat()
{
	type = "Cat";
	std::cout << "\e[1;33mDefault Constructor called of Cat\e[0m" << std::endl;
}

Cat::Cat(const Cat &copy)
{
	type = copy.type;
	std::cout << "\e[1;33mCopy Constructor called of Cat\e[0m" << std::endl;
}

// Destructor
Cat::~Cat()
{
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

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
