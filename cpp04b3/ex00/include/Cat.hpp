/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:27:34 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/30 13:39:38 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat : public Animal
{
public:
	// Constructors
	Cat();
	Cat(const Cat &copy);

	// Destructor
	~Cat();

	// Operators
	Cat &operator=(const Cat &assign);

	// Member functions
	void makeSound() const;
};

#endif
