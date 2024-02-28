/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:00:31 by rleskine          #+#    #+#             */
/*   Updated: 2024/01/23 15:15:40 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(std::string const &type = "cure");
	Cure(const Cure &copy);
	virtual ~Cure();

	virtual Cure &operator=(const Cure &assign);

	std::string const &getType() const;
	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};

#endif /* CURE_HPP */
