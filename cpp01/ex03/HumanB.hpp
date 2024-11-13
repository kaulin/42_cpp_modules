/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:18:19 by jajuntti          #+#    #+#             */
/*   Updated: 2024/11/13 08:53:34 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanB_HPP
# define HumanB_HPP

#include <iostream>
#include "Weapon.hpp"

class	HumanB
{
private:
	std::string	_name;
	Weapon*		_weapon;
public:
	// Construct
	HumanB(std::string name);
	// Destroy
	~HumanB();
	// Get
	// Set
	void	setWeapon(Weapon& weapon);
	// Other
	void	attack();
};

#endif