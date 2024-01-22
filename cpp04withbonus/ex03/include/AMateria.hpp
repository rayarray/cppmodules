/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:22:50 by rleskine          #+#    #+#             */
/*   Updated: 2024/01/22 16:36:02 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter;

class AMateria
{
protected:
	std::string const type;

public:
	AMateria(std::string const &type = "abstract");
	AMateria(const AMateria &copy);
	virtual ~AMateria();

	virtual AMateria &operator=(const AMateria &assign) = 0;

	std::string const &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#include "ICharacter.hpp"

#endif /* AMATERIA_HPP */
