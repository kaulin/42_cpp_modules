/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:21:15 by jajuntti          #+#    #+#             */
/*   Updated: 2024/10/30 16:47:53 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
		Contact	contacts[8];
		int		nextIndex;
		int		storedContacts;
	public:
		// Construct
		PhoneBook();
		// Destroy
		~PhoneBook();
		// Get
		// Set
		// Other
		void	add();
		void	search();
		void	run();
};

#endif