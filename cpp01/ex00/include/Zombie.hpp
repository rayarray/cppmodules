/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:20:53 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/15 22:44:19 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
    public:
        Zombie();
        Zombie(std::string);
        ~Zombie();
        void    announce();

    private:
        std::string name;
};

Zombie  *newZombie(std::string name);
void    randomChump(std::string name);

#endif