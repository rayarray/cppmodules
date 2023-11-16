/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:11:40 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/16 11:08:19 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Zombie.hpp"

int main(int ac, char **ag) {
    if (ac < 2) {
        std::cout << "usage: mkZombieHorde A [B]\n" << "\tWhere A the number of zombies to create"
            << "\n\tand B is a the name to set for all the zombies\n";
        return 0;
    }
	std::istringstream	stream(*(ag + 1));
	int					hordeSize;
	Zombie				*horde;
	stream >> hordeSize;
	if (ac < 3)
		horde = zombieHorde(hordeSize);
	else
    	horde = zombieHorde(hordeSize, *(ag + 2));
	delete[] horde;
	return 0;
}