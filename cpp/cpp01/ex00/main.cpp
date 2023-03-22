/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:16:21 by jaeywon           #+#    #+#             */
/*   Updated: 2023/03/22 14:56:31 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void){
	Zombie stacktomato1("tomato");
	Zombie *heapcoriander = newZombie("coriander");

	randomChump("tomato2");
	stacktomato1.announce();
	heapcoriander->announce();
	delete heapcoriander;
	return (0);
}