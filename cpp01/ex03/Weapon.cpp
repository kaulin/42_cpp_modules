/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:22:35 by jajuntti          #+#    #+#             */
/*   Updated: 2024/11/06 14:41:22 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Construct
Weapon::Weapon ( std::string type ) { _type = type; }
// Destruct
Weapon::~Weapon() {}
// Get
const std::string&	Weapon::getType() {
	std::string&	type_ref = _type;
	return type_ref;
	}
// Set
void	Weapon::setType( std::string type ) { _type = type; }