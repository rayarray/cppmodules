/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:02:46 by rleskine          #+#    #+#             */
/*   Updated: 2024/01/22 15:54:55 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(std::string const &type) : AMateria(type) {}

Ice::Ice(const Ice &) {}

Ice::~Ice() {}

AMateria &Ice::operator=(const AMateria &assign)
{
	(void)assign;
	return *this;
}

std::string const &Ice::getType() const
{
	return type;
}

AMateria *Ice::clone() const
{
	return nullptr;
}

void Ice::use(ICharacter &target)
{
	std::cout << type << " shoots an ice bolt at " << target.getName() << std::endl;
}