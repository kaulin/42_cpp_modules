/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:18:19 by jajuntti          #+#    #+#             */
/*   Updated: 2024/11/06 14:14:50 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanA_HPP
# define HumanA_HPP

#include <iostream>
#include "Weapon.hpp"

class	HumanA
{
private:
	std::string	_name;
	Weapon&		_weapon;
public:
	// Construct
	HumanA( std::string name, Weapon& weapon );
	// Destroy
	~HumanA();
	// Get
	// Set
	// Other
	void	attack( void );
};

#endif