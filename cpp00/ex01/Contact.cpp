/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:21:07 by jajuntti          #+#    #+#             */
/*   Updated: 2024/10/30 16:20:06 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Construct
Contact::Contact() {}
// Destruct
Contact::~Contact() {}
// Get
std::string	Contact::getFirstName() const { return this->_firstName; }
std::string	Contact::getLastName() const { return this->_lastName; }
std::string	Contact::getNickname() const { return this->_nickname; }
std::string	Contact::getPhoneNumber() const { return this->_phoneNumber; }
std::string	Contact::getDarkestSecret() const { return this->_darkestSecret; }
// Set
void	Contact::setFirstName(std::string name) { this->_firstName = name; }
void	Contact::setLastName(std::string name) { this->_firstName = name; }
void	Contact::setNickname(std::string name) { this->_firstName = name; }
void	Contact::setPhoneNumber(std::string number) { this->_firstName = number; }
void	Contact::setDarkestSecret(std::string secret) { this->_firstName = secret; }
// Other