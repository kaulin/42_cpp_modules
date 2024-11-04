/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:36:15 by jajuntti          #+#    #+#             */
/*   Updated: 2024/11/04 14:32:58 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void) {
	Zombie	z0;
	Zombie	*z1;
	Zombie	*z2;

	z0.setName("z0");
	z0.announce();
	z1 = new Zombie;
	z1->setName("z1");
	z1->announce();
	z2 = newZombie("z2");
	randomChump("z3");
	delete z2;
	delete z1;
	return 0;
}