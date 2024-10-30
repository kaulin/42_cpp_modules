/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:21:11 by jajuntti          #+#    #+#             */
/*   Updated: 2024/10/30 17:02:10 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// Construct
PhoneBook::PhoneBook() {
	nextIndex = 0;
	storedContacts = 0;
}
// Destruct
PhoneBook::~PhoneBook() {}
// Get
// Set
// Other
void	PhoneBook::add() {
	std::cout << "Adding\n";
}
void	PhoneBook::search() {
	std::cout << "Searching\n";
}

void	PhoneBook::run() {
	std::string	input;
	
	std::cout << "PhoneBook started. Commands are ADD/SEARCH/EXIT\n";
	while (true)
	{
		std::getline(std::cin, input);
		if (!input.compare("ADD"))
			add();
		else if (!input.compare("SEARCH"))
			search();
		else if (!input.compare("EXIT"))
			return ;
	}
}
