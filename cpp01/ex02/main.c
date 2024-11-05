/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:50:30 by jajuntti          #+#    #+#             */
/*   Updated: 2024/11/05 15:18:27 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void) {
	std::string	stringVAR = "HI THIS IS BRAIN";
	std::string	*stringPTR = &stringVAR;
	std::string	&stringREF = stringVAR;
	
	std::cout << "Address of stringVAR: " << &stringVAR << std::endl;
	std::cout << "Address held by stringPTR: " << &stringPTR << std::endl;
	std::cout << "Address held by stringREF: " << &stringREF << std::endl;

	std::cout << "Value of stringVAR: " << stringVAR << std::endl;
	std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of stringREF: " << *stringPTR << std::endl;

	return 0;
}