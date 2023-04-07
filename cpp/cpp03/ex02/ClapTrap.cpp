/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:59:04 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/08 04:11:17 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	this->name = "";
	this->Hit_Points = 10;
	this->Energy_points = 10;
	this->Attack_damage = 0;
	std::cout << "ClapTrap Constructor(Default) called" << std::endl;
}

ClapTrap::ClapTrap(std::string name){
	this->name = name;
	this->Hit_Points = 10;
	this->Energy_points = 10;
	this->Attack_damage = 0;
	std::cout << "ClapTrap Constructor("<< this->name << ") called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src){
	this->name = src.name;
	this->Hit_Points = src.Hit_Points;
	this->Energy_points = src.Energy_points;
	this->Attack_damage = src.Attack_damage;
	std::cout << "ClapTrap copy Constructor("<< this->name << ") called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src){
	this->name = src.name;
	this->Hit_Points = src.Hit_Points;
	this->Energy_points = src.Energy_points;
	this->Attack_damage = src.Attack_damage;
	std::cout << "ClapTrap Constructor("<< this->name << ") called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target){
	if (!this->Hit_Points || !this->Energy_points){
		std::cout << "ClapTrap " << this->name << "fainted and couldn't move...." << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->name <<  " attacks " << target << ", causing " \
		<< this->Attack_damage << " points of damage!" << std::endl;
		this->Energy_points--;
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	if (amount > this->Hit_Points){
		this->Hit_Points = 0;
	}
	else {
		this->Hit_Points -= amount;
		std::cout << "ClapTrap " << this->name << " has taken " << amount << " damage!!!" << std::endl;
	}
	if (!this->Hit_Points){
		std::cout << "ClapTrap " << this->name << " fainted and couldn't move...." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!this->Hit_Points || !this->Energy_points){
		std::cout << "ClapTrap " << this->name << " fainted and couldn't move...." << std::endl;
	}
	else {
		this->Hit_Points += amount;
		this->Energy_points--;
		std::cout << "ClapTrap " << this->name << " has been repaired of " << amount << " Hit points." << std::endl;
		std::cout << this->name << " has now " << this->Hit_Points << " Hit points" << std::endl;
	}
}