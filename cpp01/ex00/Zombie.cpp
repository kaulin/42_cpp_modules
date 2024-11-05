/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:22:35 by jajuntti          #+#    #+#             */
/*   Updated: 2024/11/05 09:34:04 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Private

// Construct
Zombie::Zombie () {}
Zombie::Zombie (std::string name) { _name = name; }
// Destruct
Zombie::~Zombie() { std::cout << _name << std::endl; }
// Get
// Set
void Zombie::setName(std::string name) { _name = name; }
// Other
void	Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}