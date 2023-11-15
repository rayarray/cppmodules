/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:06:57 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/15 13:44:34 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
    public:
        Contact();
        void    setInfo(std::string s);
        void    reset();
        void    print();
        void    indexPrint();
        std::string info;
    private:
        std::string truncate(std::string s);
        int         index;
        std::string fields[5];
};

#endif
