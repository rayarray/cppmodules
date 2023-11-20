/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:56:23 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/17 11:31:07 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string type) : type(type) {}

const std::string&	Weapon::getType() {
	return type;
}

void	Weapon::setType(std::string type) {
	this->type = type;
}