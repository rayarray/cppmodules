/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:02:46 by rleskine          #+#    #+#             */
/*   Updated: 2024/01/24 10:41:36 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(std::string const &type) : AMateria(type) {}

Cure::Cure(const Cure &copy) : AMateria(copy.getType()) {}

Cure::~Cure() {}

Cure &Cure::operator=(const Cure &assign)
{
	if (this == &assign)
		return *this;
	Cure(assign.getType());
	return *this;
}

std::string const &Cure::getType() const
{
	return type;
}

AMateria *Cure::clone() const
{
	return new Cure(this->getType());
}

void Cure::use(ICharacter &target)
{
	std::cout << "\e[1;92m* " << type << " heals " << target.getName() << "'s wounds *\e[0;37m" << std::endl;
}
