/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:15:52 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/10 16:23:54 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	}
	else {
		for (int i = 1; i < ac; i++)
		{
			for (int j = 0; i < av[i][j]; j++)
			{
				std::cout << (char)toupper(av[i][j]);
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
