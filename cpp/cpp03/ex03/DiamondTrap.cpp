/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:07:03 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/19 19:14:14 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap:: DiamondTrap() : name(ClapTrap::name) {
	this->name = "";
	this->Attack_damage = 30;
	ClapTrap::name = name + "_clap_name";
	std::cout << "DiamondTrap default constructor called" << std::endl;
}
 
DiamondTrap:: DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name) {
	this->name = name;
	this->Attack_damage = 30;
	ClapTrap::name + name + "_clap_name";
	std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamond) {
	*this = diamond;
	std::cout << "DiamondTrap " << name << " copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->name << " destructor called" << std::endl;
}

DiamondTrap&  DiamondTrap::operator=(const  DiamondTrap& diamond) {
	if (this == &diamond)
		return (*this);
	this->name = diamond.name;
	this->Attack_damage = diamond.Attack_damage;
	this->Energy_points = diamond.Energy_points;
	this->Hit_Points = diamond.Hit_Points;
	std::cout << "DiamondTrap operator = " << name << " called" << std::endl;
	return (*this);
}

void DiamondTrap::whoAmI(void){
	std::cout << "This DiamondTrap name is " << this->name << " and This ClapTrap name is " << ClapTrap::name << std::endl;
}

void DiamondTrap::printStatus(void) {
	std::cout << "Name : " << name << std::endl;
	std::cout << "Hit_points : " << Hit_Points << std::endl;
	std::cout << "Energy_point : " << Energy_points << std::endl;
	std::cout << "Attack_damage : " << Attack_damage << std::endl;
}