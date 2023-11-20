/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:53:16 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/17 13:43:49 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
    public:
		HumanB(std::string name);
        void		attack();
		void		setWeapon(Weapon &weapon);
    private:
        std::string name;
		Weapon		*weapon;
};

#endif