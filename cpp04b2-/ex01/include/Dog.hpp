/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:27:34 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/30 19:04:34 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *brain;

public:
	// Constructors
	Dog();
	Dog(const Dog &copy);

	// Destructor
	~Dog();

	// Operators
	Dog &operator=(const Dog &assign);

	// Member functions
	void makeSound() const;
	void haveIdea(const std::string &idea) const;
	void mindRead(bool showPointers = false) const;
};

#endif
