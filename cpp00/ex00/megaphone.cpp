/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:26:08 by jajuntti          #+#    #+#             */
/*   Updated: 2024/10/02 10:45:17 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char *toUpper(char *str)
{
	for (int i = 0; str[i]; i++)
		str[i] = std::toupper(str[i]);
	return str;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::cout<< toUpper(argv[i]);
		}
		std::cout << std::endl;
	}
	return (0);
}