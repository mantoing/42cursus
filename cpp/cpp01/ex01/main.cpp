/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:57:00 by jaeywon           #+#    #+#             */
/*   Updated: 2023/03/22 15:59:17 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void){
	Zombie *Zombie = zombieHorde(10, "tomato");

	for(int i=0; i < 10; i++)
		Zombie[i].announce();
	delete[] Zombie;
	return (0);
}