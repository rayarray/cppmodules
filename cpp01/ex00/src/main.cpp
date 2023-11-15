/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:11:40 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/15 22:46:37 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(int ac, char **ag) {
    if (ac < 2) {
        std::cout << "usage: mkZombie A [B]\n" << "\tWhere A is a zombie created with randomChump function"
            << "\n\tand B is a zombie created with newZombie function\n";
        return 0;
    }
    randomChump(*(ag + 1));
    if (ac > 2) {
        Zombie *z1 = newZombie(*(ag + 2));
        z1->announce();
        delete(z1);
    }
}