/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:20:53 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/27 14:02:24 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
	private:
        std::string name;
    public:
        Zombie();
        Zombie(std::string);
        ~Zombie();
		void	setName(std::string name);
        void    announce();
};

Zombie  *zombieHorde(int N, std::string name);
Zombie  *zombieHorde(int N);

#endif