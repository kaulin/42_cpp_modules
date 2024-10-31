/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:21:11 by jajuntti          #+#    #+#             */
/*   Updated: 2024/10/31 16:32:55 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// Private
void	PhoneBook::_addContact(Contact newContact) {
	_contacts[_nextIndex++] = newContact;
	if (_nextIndex > 7) _nextIndex = 0;
	if (_storedContacts < 8) _storedContacts++;
}

std::string	getInput(std::string label) {
	std::string	input;

	while (input.empty()) {
		std::cout << "Provide " << label << std::endl;
		std::getline(std::cin, input);
	}
	return input;
}

// Construct
PhoneBook::PhoneBook() {
	_nextIndex = 0;
	_storedContacts = 0;
}
// Destruct
PhoneBook::~PhoneBook() {}
// Get
// Set
// Other
std::string	PhoneBook::add() {
	Contact		newContact;
	std::string	input;

	std::cout << "Adding contact" << std::endl;
	input = getInput("first name");
	newContact.setFirstName(input);
	input = getInput("last name");
	newContact.setLastName(input);
	input = getInput("nickname");
	newContact.setNickname(input);
	input = getInput("phone number (7 or 8 digits)");
	while (!newContact.verifyPhoneNumber(input))
		input = getInput("phone number (7 or 8 digits)");
	newContact.setPhoneNumber(input);
	input = getInput("darkest secret");
	newContact.setDarkestSecret(input);
	_addContact(newContact);
	return "Contact added";
}

std::string	PhoneBook::search() {
	int			index = 0;
	std::string	input;

	while (index < _storedContacts) {
		_contacts[index].printContact(true, index);
		index++;
	}
	input = getInput("desired contact index");
	std::stringstream(input) >> index;
	if (index < 0 || index > 7)
		return "Error: invalid index";
	_contacts[index].printContact(false, index);
	return "Search successful";
}

void	PhoneBook::run() {
	std::string	input;
	
	std::cout << "PhoneBook started" << std::endl;
	while (true)
	{
		std::cout << "Commands are ADD, SEARCH and EXIT" << std::endl;
		std::getline(std::cin, input);
		if (!input.compare("ADD")) std::cout << add() << std::endl;
		else if (!input.compare("SEARCH")) std::cout << search() << std::endl;
		else if (!input.compare("EXIT")) {
			std::cout << "Exiting PhoneBook" << std::endl;
			return ;
		}
	}
}
