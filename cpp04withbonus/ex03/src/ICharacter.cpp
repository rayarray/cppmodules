/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:11:06 by rleskine          #+#    #+#             */
/*   Updated: 2024/01/22 17:14:03 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

// Constructors
ICharacter::ICharacter() {}

ICharacter::ICharacter(const ICharacter &copy)
{
	(void)copy;
}

// Destructor
ICharacter::~ICharacter() {}

// Operators
ICharacter &ICharacter::operator=(const ICharacter &assign)
{
	(void)assign;
	return *this;
}