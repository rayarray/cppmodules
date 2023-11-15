/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:37:38 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/15 13:25:47 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <PhoneBook.hpp>

int getCmd(void)
{
    std::string options[] = { "ADD", "SEARCH", "EXIT", "" };
    std::string input;
    int         index = -1;

    std::cout << "Welcome to My AweSome PhoneBook! Please enter ADD, SEARCH or EXIT\n";
    while (index == -1) 
    {
        std::cout << "ADD/SEARCH/EXIT> ";
        std::getline(std::cin, input);
        while (options[++index].size() > 0)
        {
            if (input.compare(options[index]) == 0)
                break;
        }
        if (options[index].size() < 1)
            index = -1;
    }
    return (index);
}

int main(void)
{
    PhoneBook   book;
    
    for (int i = getCmd(); i != 2; i = getCmd())
    {
        switch (i)
        {
            case 0:
                book.add();
                break;
            case 1:
                book.search();
        }
    }
    return (0);
}
