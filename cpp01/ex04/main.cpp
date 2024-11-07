/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:36:15 by jajuntti          #+#    #+#             */
/*   Updated: 2024/11/07 15:32:55 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	openInfile(const std::string& infilePath, std::ifstream& infile) {
	infile.open(infilePath, std::ios::in);
	if (!infile) {
		std::cout << "The infile might not exist, or I lack authorization" << std::endl;
		return 1;
	}
	return 0;
}

int	openOutfile(const std::string& path, std::ofstream& outfile) {
	std::string	outfilePath(path + ".replace");
	outfile.open(outfilePath);
	if (!outfile) {
		std::cout << "The outfile exists and I lack permissions to touch it" << std::endl;
		return 1;
	}
	return 0;
}

void	reeplace(const std::string& s1, const std::string& s2, std::string& line) {
	std::size_t	pos;
	
	pos = line.find(s1);
	line.erase(pos, s1.length());
	line.insert(pos, s2);
}

void	reeplaceAll(const std::string& s1, const std::string& s2, std::string& line) {
	while (line.find(s1) != std::string::npos) reeplace(s1, s2, line);
}

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "I desire arguments three" << std::endl;
		return 2;
	}
	
	std::string		path(argv[1]);
	std::string		s1(argv[2]);
	std::string		s2(argv[3]);
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		line;

	if (path.empty()) {
		 std::cout << "You must tell me which file you want altered" << std::endl;
		return 1;
	}
	if (s1.empty()) {
		std::cout << "Can't search for nothing, as nothing is everywhere" << std::endl;
		return 1;
	}
	if (openInfile(path, infile) || openOutfile(path, outfile))
		return 1;
	while (std::getline(infile, line)) {
		reeplaceAll(s1, s2, line);
		outfile << line << std::endl;
	}
	return 0;
};