/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:38:43 by jaeywon           #+#    #+#             */
/*   Updated: 2023/03/23 20:43:46 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av){
	
	if (ac != 2){
		std::cout << "ac error" << std::endl;
		return (1);
	}
	Harl harl;

	harl.complain(av[1]);
	return (0);
}