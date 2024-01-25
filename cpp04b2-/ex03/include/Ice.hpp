/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:00:31 by rleskine          #+#    #+#             */
/*   Updated: 2024/01/23 15:15:40 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice(std::string const &type = "ice");
	Ice(const Ice &copy);
	virtual ~Ice();

	virtual Ice &operator=(const Ice &assign);

	std::string const &getType() const;
	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};

#endif /* ICE_HPP */
