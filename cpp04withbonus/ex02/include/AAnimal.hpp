/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:48:07 by rleskine          #+#    #+#             */
/*   Updated: 2023/12/01 09:22:25 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
public:
	// Constructors
	AAnimal();
	AAnimal(const AAnimal &copy);

	// Destructor
	virtual ~AAnimal();

	// Operators
	// virtual AAnimal &operator=(const AAnimal &assign) = 0;

	// Getters / Setters
	virtual const std::string &getType() const = 0;

	// Member functions
	virtual void makeSound() const = 0;
	virtual void haveIdea(const std::string &idea) const = 0;
	virtual void mindRead(bool showPointers = false) const = 0;

protected:
	std::string type;
};

#endif