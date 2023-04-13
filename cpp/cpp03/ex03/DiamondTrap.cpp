/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:07:03 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/13 03:13:05 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap:: DiamondTrap() : _name(ClapTrap::name) {
	this->_name = "";
	this->Attack_damage = 30;
	ClapTrap::name = name + "_clap_name";
	std::cout << "DiamondTrap default constructor called" << std::endl;
}
 
DiamondTrap:: DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name) {
	this->_name = name;
	this->Attack_damage = 30;
	ClapTrap::name + name + "_clap_name";
	std::cout << "DiamondTrap " << _name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamond) {
	*this = diamond;
	std::cout << "DiamondTrap " << _name << " copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->_name << " destructor called" << std::endl;
}

DiamondTrap&  DiamondTrap::operator=(const  DiamondTrap& diamond) {
	if (this == &diamond)
		return (*this);
	this->_name = diamond._name;
	this->Attack_damage = diamond.Attack_damage;
	this->Energy_points = diamond.Energy_points;
	this->Hit_Points = diamond.Hit_Points;
	std::cout << "DiamondTrap operator = " << _name << " called" << std::endl;
	return (*this);
}

void DiamondTrap::whoAmI(void){
	std::cout << "This DiamondTrap name is " << this->_name << " and This ClapTrap name is " << ClapTrap::name << std::endl;
}

void DiamondTrap::printStatus(void) {
	std::cout << "Name : " << _name << std::endl;
	std::cout << "Hit_points : " << Hit_Points << std::endl;
	std::cout << "Energy_point : " << Energy_points << std::endl;
	std::cout << "Attack_damage : " << Attack_damage << std::endl;
}