/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:31:18 by jaeywon           #+#    #+#             */
/*   Updated: 2023/03/22 20:20:58 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const	std::string& Weapon::getType(void){
	return (this->type);
}

void	Weapon::setType(std::string type){
	this->type = type;
}

Weapon::Weapon(std::string type){
	this->type = type;
}
Weapon::Weapon(void){
	
}