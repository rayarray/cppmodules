/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:03:56 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/15 08:00:24 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void    strToUpper(char *s)
{
    for (; s && *s; s++)
        *s = toupper(*s);
}

std::string    strClassToUpper(std::string s)
{
    for (size_t i = 0; i < s.size(); i++) {
        //std::string c(1, toupper(s[i]));
        s.replace(i, 1, 1, toupper(s[i]));
    }
    return (s);
}

int main(int ac, char **ag)
{
    if (ac <= 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    //for (strToUpper(*(++ag)); *ag; strToUpper(*(++ag))) {
    //    std::cout << *ag;
    for (std::string s; *(ag + 1); ag++) {
        s = *(ag + 1);
        std::cout << strClassToUpper(s);
    }
    std::cout << "\n";
    return (0);
}
