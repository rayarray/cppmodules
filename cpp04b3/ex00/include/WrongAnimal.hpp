/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:48:14 by rleskine          #+#    #+#             */
/*   Updated: 2024/01/29 10:20:32 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
public:
	// Constructors
	WrongAnimal();
	WrongAnimal(const WrongAnimal &copy);

	// Destructor
	~WrongAnimal();

	// Operators
	WrongAnimal &operator=(const WrongAnimal &assign);

	// Getters / Setters
	const std::string &getType() const;

	// Member functions
	virtual void makeSound() const;

protected:
	std::string type;
};

#endif