/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:27:34 by rleskine          #+#    #+#             */
/*   Updated: 2023/12/01 10:11:34 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
private:
	Brain *brain;

public:
	// Constructors
	Dog();
	Dog(const Dog &copy);

	// Destructor
	virtual ~Dog();

	// Operators
	Dog &operator=(const Dog &assign);

	// Member functions
	const std::string &getType() const;
	void makeSound() const;
	void haveIdea(const std::string &idea) const;
	void mindRead(bool showPointers = false) const;
};

#endif
