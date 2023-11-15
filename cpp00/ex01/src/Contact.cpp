/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:43:08 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/15 13:42:11 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() {
    index = 0;
}

void    Contact::setInfo(std::string s)
{
    if (index > 4)
        return ;
    fields[index++] = s;
}

void    Contact::reset() {
    index = 0;
}

void    Contact::print()
{
    if (index == 0) return;
    //std::cout << "\tName : " << firstName << " \"" << nickName << "\" " << lastName << "\n";
    std::cout << "\tFirst name: " << fields[0] << "\n";
    std::cout << "\tLast name: " << fields[1] << "\n";
    std::cout << "\tNickname: " << fields[2] << "\n";
    std::cout << "\tNumber: " << fields[3] << "\n";
    std::cout << "\tDarkest secret: " << fields[4] << "\n";
}

void    Contact::indexPrint()
{
    std::cout << "|" << std::setfill(' ') << std::setw(10) << truncate(fields[0]);
    std::cout << "|" << std::setfill(' ') << std::setw(10) << truncate(fields[1]);
    std::cout << "|" << std::setfill(' ') << std::setw(10) << truncate(fields[2]);
    std::cout << "|" << std::setfill(' ') << std::setw(10) << truncate(fields[3]);
    std::cout << "|" << std::setfill(' ') << std::setw(10) << truncate(fields[4]) << "|\n";
}

std::string Contact::truncate(std::string s)
{
    if (s.size() <= 10)
        return (s);
    else
        return (s.substr(0, 9) + ".");
}
