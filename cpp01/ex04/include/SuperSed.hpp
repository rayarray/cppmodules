/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supersed.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:52:33 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/20 13:16:36 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SUPERSED_HPP
#define	SUPERSED_HPP

#include <string>
#include <iostream>
#include <fstream>

class SuperSed
{
private:
	std::ifstream&			infile;
	std::ofstream&			outfile;
public:
	SuperSed(std::ifstream& infile, std::ofstream& outfile);
	~SuperSed();
	bool	checkFiles();
	bool	replacePattern(std::string pattern, std::string replace);
};

#endif
