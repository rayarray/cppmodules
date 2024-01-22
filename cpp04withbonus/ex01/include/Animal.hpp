/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:48:07 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/30 19:07:06 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
public:
	// Constructors
	Animal();
	Animal(const Animal &copy);

	// Destructor
	virtual ~Animal();

	// Operators
	Animal &operator=(const Animal &assign);

	// Getters / Setters
	const std::string &getType() const;

	// Member functions
	virtual void makeSound() const;
	virtual void haveIdea(const std::string &idea) const;
	virtual void mindRead(bool showPointers = false) const;

protected:
	std::string type;
};

#endif