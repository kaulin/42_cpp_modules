/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:22:35 by jajuntti          #+#    #+#             */
/*   Updated: 2024/11/13 08:53:03 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Construct
HumanA::HumanA (std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {}
// Destruct
HumanA::~HumanA() {}
// Get
// Set
// Other
void	HumanA::attack(void) {
	if (_weapon.getType().empty())
		std::cout << _name << ": attacks with their fists" << std::endl;
	else
		std::cout << _name << ": attacks with their " << _weapon.getType() << std::endl;
}