/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:27:34 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/30 19:04:24 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *brain;

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
	void haveIdea(const std::string &idea) const;
	void mindRead(bool showPointers = false) const;
};

#endif
