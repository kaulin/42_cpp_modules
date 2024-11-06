/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:18:19 by jajuntti          #+#    #+#             */
/*   Updated: 2024/11/05 10:55:06 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Class_HPP
# define Class_HPP

#include <iostream>

class Class
{
private:
	std::string	_name;
public:
	// Construct
	Class();
	Class( std::string name );
	// Destroy
	~Class();
	// Get
	std::string	getName(void);
	// Set
	void	setName( std::string _name );
	// Other
};

#endif