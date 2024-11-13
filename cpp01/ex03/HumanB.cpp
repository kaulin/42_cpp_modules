/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:22:35 by jajuntti          #+#    #+#             */
/*   Updated: 2024/11/13 08:53:25 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// Construct
HumanB::HumanB (std::string name) : _name(name), _weapon(nullptr) {}
// Destruct
HumanB::~HumanB() {}
// Get
// Set
void	HumanB::setWeapon(Weapon& weapon) { _weapon = &weapon; }
// Other
void	HumanB::attack() {
	if (_weapon == nullptr || _weapon->getType().empty())
		std::cout << _name << ": attacks with their fists" << std::endl;
	else
		std::cout << _name << ": attacks with their " << _weapon->getType() << std::endl;
}