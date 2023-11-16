/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:45:22 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/16 11:10:08 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <sstream>
#include <iostream>
#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	if (N <= 0) return NULL;
	Zombie	*horde = new Zombie[N];
	while (--N >= 0) {
		horde[N].setName(name);
		horde[N].announce();
	}
	return horde;
}

Zombie	*zombieHorde(int N) {
	if (N <= 0) return NULL;
	Zombie	*horde = new Zombie[N];
	while (--N >= 0) {
		std::stringstream	ss;
		std::string			str;
		ss.clear();
		ss << N + 1;
		ss >> str;
		horde[N].setName(str);
		horde[N].announce();
	}
	return horde;
}

/* Zombie	*zombieHorde(int N, std::string name) {
	//Zombie	*horde;

	if (N < 0) return NULL;
	//horde = (Zombie *)malloc(sizeof(Zombie) * N);
	//while (--N >= 0) {
	//	(horde + N)->Zombie::Zombie(name);
	//}
	std::vector<Zombie> horde(N);
	for (int i = 0; i < N; i++) {
		horde[N].setName(name);
		horde[N].announce();
	}
	return &horde[0];
} */

/*Zombie	*zombieHorde(int N, std::string name) {
	Zombie	*horde;

	if (N < 0) return NULL;
	horde = (Zombie *)malloc(sizeof(Zombie) * N);
	while (--N >= 0) {
		(horde + N)->setName(name);
	}
	return horde;
} */
