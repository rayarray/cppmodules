/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:27:34 by rleskine          #+#    #+#             */
/*   Updated: 2023/12/01 10:11:44 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain *brain;

public:
	// Constructors
	Cat();
	Cat(const Cat &copy);

	// Destructor
	virtual ~Cat();

	// Operators
	Cat &operator=(const Cat &assign);

	// Member functions
	const std::string &getType() const;
	void makeSound() const;
	void haveIdea(const std::string &idea) const;
	void mindRead(bool showPointers = false) const;
};

#endif
