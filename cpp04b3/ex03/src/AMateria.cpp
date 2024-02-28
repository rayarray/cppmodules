/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:34:39 by rleskine          #+#    #+#             */
/*   Updated: 2024/02/28 10:15:38 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::AMateria(const AMateria &) {}

AMateria::~AMateria() {}

// AMateria &AMateria::operator=(const AMateria &) {}

std::string const &AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}
