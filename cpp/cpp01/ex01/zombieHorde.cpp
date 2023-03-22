/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:53:00 by jaeywon           #+#    #+#             */
/*   Updated: 2023/03/22 16:02:30 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){
	Zombie *zombieHorde = new Zombie[N];

	for(int i=0; i < N; i++)
		zombieHorde[i].setName(name);
	return (zombieHorde);
}