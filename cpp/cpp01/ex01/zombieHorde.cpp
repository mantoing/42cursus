/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:53:00 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/10 21:02:12 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde(int N, std::string name){
	Zombie *zombieHorde = new Zombie[N];
	std::stringstream	stringStream;

	for(int i=0; i < N; i++){
		stringStream.str(std::string());
			stringStream << i + 1;
		zombieHorde[i].setName(name + "_" + stringStream.str());
	}
	return (zombieHorde);
}