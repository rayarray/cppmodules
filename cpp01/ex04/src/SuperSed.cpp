/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supersed.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:06:31 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/20 13:39:36 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SuperSed.hpp>

SuperSed::SuperSed(std::ifstream& infile, std::ofstream& outfile) : infile(infile), outfile(outfile) {}

SuperSed::~SuperSed() {}

bool	SuperSed::checkFiles() {
	if (infile.is_open() && outfile.is_open())
		return true;
	if (!infile.is_open())
		std::cout << "Error opening input file" << std::endl;
	if (!outfile.is_open())
		std::cout << "Error opening output file" << std::endl;
	return false;
}

bool	SuperSed::replacePattern(std::string pattern, std::string replace) {
	std::string line;
	
	while (getline(infile, line)) {
		std::size_t start = 0;
		std::size_t found = line.find(pattern, start);

		while (found != std::string::npos) {
			if ((outfile << line.substr(start, found - start) << replace) == false) {
				std::cout << "File write failed!" << std::endl;
				return false;
			}
			start = found + pattern.size();
			found = line.find(pattern, start);
		}
		outfile << line.substr(start, line.size()) << std::endl;
	}
	return true;
}