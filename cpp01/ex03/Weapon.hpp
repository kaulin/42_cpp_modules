/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:18:19 by jajuntti          #+#    #+#             */
/*   Updated: 2024/11/06 14:40:52 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Weapon_HPP
#define Weapon_HPP

#include <iostream>

class	Weapon
{
private:
	std::string	_type;
public:
	// Construct
	Weapon( std::string type );
	// Destroy
	~Weapon();
	// Get
	const	std::string& getType( void );
	// Set
	void	setType( std::string _type );
	// Other
};

#endif