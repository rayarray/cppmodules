/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:16:32 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/15 14:17:37 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <sstream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    index = 0;
}

std::string PhoneBook::getInput(std::string prompt)
{
    std::string s;

    while (s.size() == 0)
    {
        std::cout << prompt;
        std::getline(std::cin, s);
    }
    return (s);
}

void    PhoneBook::add()
{
    int         i = index % 8;

    contacts[i].reset();
    std::cout << "Adding new contact. Please enter the following information, no empty fields allowed: \n";
    contacts[i].setInfo(getInput("First name :"));
    contacts[i].setInfo(getInput("Last name :"));
    contacts[i].setInfo(getInput("Nickname :"));
    contacts[i].setInfo(getInput("Phone number :"));
    contacts[i].setInfo(getInput("Darkest secret :"));
    if (index <= 7)
        std::cout << "Contact " << index + 1 << " added\n";
    else
        std::cout << "Contact " << index % 8 + 1 << " overwritten\n";
    index++;
    if (index < 0)
        index = (index - 1) % 8 + 1;
}

void    PhoneBook::search()
{
    std::string         s;
    std::stringstream   stream;
    int                 i = 0;
    int                 lastEntry = std::min(8, index);

    if (index == 0)
        std::cout << "No entries to search!\n";
    if (index <= 1)
    {
        contacts[0].print();
        return;
    }
    std::cout << " |First name| Last name|  Nickname|Phone nmbr|DarkSecret|\n";
    while (i < lastEntry)
    {
        std::cout << i + 1;
        contacts[i++].indexPrint();
    }
    i = -1;
    while (index > 0 && (i < 1 || i > lastEntry))
    {
        std::cout << "Please enter the number of contact to print [1-" << lastEntry << "]\n> ";
        std::getline(std::cin, s);
        stream.clear();
        stream.str(s);
        stream >> i;
        if (i >= 1 && i <= lastEntry)
            break;
    }
    contacts[i - 1].print();
}
