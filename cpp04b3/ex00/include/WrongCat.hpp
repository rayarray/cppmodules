/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:27:34 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/30 14:51:23 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGWrongCAT_HPP
#define WRONGWrongCAT_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	// Constructors
	WrongCat();
	WrongCat(const WrongCat &copy);

	// Destructor
	~WrongCat();

	// Operators
	WrongCat &operator=(const WrongCat &assign);

	// Member functions
	void makeSound() const;
};

#endif
