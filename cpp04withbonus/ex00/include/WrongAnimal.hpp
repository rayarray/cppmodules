/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:48:14 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/30 14:48:35 by rleskine         ###   ########.fr       */
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
	void makeSound() const;

protected:
	std::string type;
};

#endif