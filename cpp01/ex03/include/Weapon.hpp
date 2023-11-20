/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:53:35 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/17 11:30:32 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
    public:
        Weapon();
		Weapon(std::string);
        const std::string&	getType();
        void				setType(std::string type);
    private:
        std::string type;
};

#endif