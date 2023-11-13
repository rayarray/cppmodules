/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:03:56 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/13 12:04:56 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void    strToUpper(char *s)
{
    for (; s && *s; s++)
        *s = toupper(*s);
}

int main(int ac, char **ag)
{
    if (ac <= 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (strToUpper(*(++ag)); *ag; strToUpper(*(++ag)))
        std::cout << *ag;
    std::cout << "\n";
    return (0);
}
