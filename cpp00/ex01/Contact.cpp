/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:21:07 by jajuntti          #+#    #+#             */
/*   Updated: 2024/10/31 16:36:56 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Construct
Contact::Contact() {}
// Destruct
Contact::~Contact() {}
// Get
// Set
void	Contact::setFirstName(std::string name) { this->_firstName = name; }
void	Contact::setLastName(std::string name) { this->_lastName = name; }
void	Contact::setNickname(std::string name) { this->_nickname = name; }
void	Contact::setPhoneNumber(std::string number) { this->_phoneNumber = number; }
void	Contact::setDarkestSecret(std::string secret) { this->_darkestSecret = secret; }
// Other
bool	Contact::verifyPhoneNumber(std::string phoneNumber)
{
	if (phoneNumber.length() < 7 || phoneNumber.length() > 8) return false;
	for (char c : phoneNumber) {
		if (!isdigit(c)) return false;
	}
	return true;
}

void	Contact::printContact(bool condensed, int index) {
	if (condensed) {
		std::cout.flags (std::ios::right);
		std::cout << std::setw(10) << index << "|" 
		<< std::setw(10) << (_firstName.length() > 10 ? _firstName.substr(0, 9) + "." : _firstName) << "|"
		<< std::setw(10) << (_lastName.length() > 10 ? _lastName.substr(0, 9) + "." : _lastName) << "|"
		<< std::setw(10) << (_nickname.length() > 10 ? _nickname.substr(0, 9) + "." : _nickname) << std::endl;
	}
	else {
		std::cout << "First name: " << _firstName << std::endl;
		std::cout << "Last name: " << _lastName << std::endl;
		std::cout << "Nickname: " << _nickname << std::endl;
		std::cout << "Phone number: " << _phoneNumber << std::endl;
		std::cout << "Darkest secret: " << _darkestSecret << std::endl;
	}
}