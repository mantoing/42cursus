/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:27:57 by jaeywon           #+#    #+#             */
/*   Updated: 2023/03/22 21:33:02 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name){
	this->name = name;
}

void HumanB::setWeapon(Weapon &Weapon){
	this->weapon = &Weapon;
}

void HumanB::attack(void){

}