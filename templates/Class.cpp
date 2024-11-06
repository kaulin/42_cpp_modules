/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:22:35 by jajuntti          #+#    #+#             */
/*   Updated: 2024/11/05 10:54:10 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.hpp"

// Construct
Class::Class () {}
Class::Class ( std::string name ) { _name = name; }
// Destruct
Class::~Class() { std::cout << _name << std::endl; }
// Get
std::string	Class::getName() { return _name; }
// Set
void	Class::setName( std::string name ) { _name = name; }