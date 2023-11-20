/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:14:32 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/20 13:39:21 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <SuperSed.hpp>

int	main(int ac, char **ag) {
	if (ac < 4 || ac > 4) {
		std::cout << "Usage: SuperSed pattern replace filename" << std::endl <<
			"\tEvery pattern matched in the contents of filename will be replaced with" << std::endl <<
			"\treplace and the modified contents will be written to filename.replace" << std::endl;
		return 0;
	}

	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		fname = *(ag + 3);

	infile.open(fname);
	fname += ".replace";
	outfile.open(fname);
	//std::cout << "file is_regular_file() : " << (std::filesystem::is_regular_file(p1) ? "true" : "false") << std::endl;

	SuperSed		supersed(infile, outfile);
	if (supersed.checkFiles())
		supersed.replacePattern(*(ag + 1), *(ag + 2));
	if (infile.is_open()) infile.close();
	if (outfile.is_open()) outfile.close();
	return 0;
}