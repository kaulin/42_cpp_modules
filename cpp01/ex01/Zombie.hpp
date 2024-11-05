/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:18:19 by jajuntti          #+#    #+#             */
/*   Updated: 2024/11/05 10:48:00 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Zombie_HPP
# define Zombie_HPP

#include <iostream>

class Zombie
{
private:
	std::string	_name;
public:
	// Construct
	Zombie();
	Zombie( std::string name);
	// Destroy
	~Zombie();
	// Get
	// Set
	void	setName(std::string _name);
	// Other
	void	announce(void);
};

#endif