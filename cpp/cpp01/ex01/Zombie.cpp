/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:33:01 by jaeywon           #+#    #+#             */
/*   Updated: 2023/03/22 16:02:52 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void){
	
}

Zombie::Zombie(std::string name){
	this->name = name;
}

Zombie::~Zombie(void){
	std::cout << this->name << ": is dead" << std::endl;
}

void Zombie::announce(){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name){
	this->name = name;
}