/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:21:15 by jajuntti          #+#    #+#             */
/*   Updated: 2024/11/01 09:53:25 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include "Contact.hpp"

class PhoneBook
{
		Contact	_contacts[8];
		int		_nextIndex;
		int		_storedContacts;
		void	_addContact(Contact newContact);
	public:
		// Construct
		PhoneBook();
		// Destroy
		~PhoneBook();
		// Get
		// Set
		// Other
		std::string	add();
		std::string	search();
		void		run();
};

#endif