/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:36:15 by jajuntti          #+#    #+#             */
/*   Updated: 2024/11/04 15:00:32 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main(void) {
	const int N = 5;

	Zombie	*horde = zombieHorde(N, "z0 clone");
	
	for (int i = 0; i < N; i++) { horde[i].announce(); }
	delete[] horde;
}