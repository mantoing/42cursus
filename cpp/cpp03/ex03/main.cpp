/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:32:38 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/13 03:21:38 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap jaeywon("jaeywon");
	DiamondTrap tomato("tomato");

	std::cout << "-----Frag-----" << std::endl;
	jaeywon.highFivesGuys();
	tomato.highFivesGuys();
	std::cout << "-----Scav-----" << std::endl;
	jaeywon.guardGate();
	tomato.guardGate();
	std::cout << "-----Diamond-----" << std::endl;
	jaeywon.whoAmI();
	tomato.whoAmI();
	std::cout << "-----Status-----" << std::endl;
	jaeywon.printStatus();
	tomato.printStatus();


	std::cout << "-----jaeywon attack-----" << std::endl;
	jaeywon.attack("jaeywon");
	std::cout << "-----tomato attack-----" << std::endl;
	tomato.attack("tomato");
	std::cout << "-----------------------" << std::endl;

	return (0);
}
