/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:07:00 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/15 11:14:24 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <Contact.hpp>

class PhoneBook {
    public:
        PhoneBook();
        void    add();
        void    search();
        void    exit();
    private:
        int         index;
        Contact     contacts[8];
        std::string getInput(std::string prompt);
};

#endif
