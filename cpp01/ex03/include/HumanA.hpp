/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:53:16 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/17 13:28:54 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
    public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
        void		attack();
		void		setWeapon(Weapon &weapon);
    private:
        std::string name;
		Weapon&		weapon;
};

#endif