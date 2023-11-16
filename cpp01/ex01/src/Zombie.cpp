/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:21:14 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/16 09:10:12 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() {
    name = "newZombie";
}

Zombie::Zombie(std::string name) 
    : name(name) {}

Zombie::~Zombie() {
    std::cout << name << " has been destroyed!\n";
}

void	Zombie::setName(std::string name) {
	this->name = name;
}

void    Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}