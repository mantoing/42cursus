/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:00:52 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/05 22:35:45 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	this->Hit_Points = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
	std::cout << "ScavTrap Constructor(Default) called" << std::endl;
}

ScavTrap::ScavTrap(std::string _name): ClapTrap(_name) {
	this->name = _name;
	this->Hit_Points = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
	std::cout << "ScavTrap Constructor("<< this->name << ") called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& scav){
	this->name = scav.name;
	this->Hit_Points = scav.Hit_Points;
	this->Energy_points = scav.Energy_points;
	this->Hit_Points = scav.Hit_Points;
	std::cout << "ScavTrap Constructor("<< this->name << ") called" << std::endl;
	return (*this);
}

void	ScavTrap::attack(const std::string& target){
	if (!this->Hit_Points || !this->Energy_points){
		std::cout << "ScavTrap " << this->name << "fainted and couldn't move...." << std::endl;
	}
	else {
		std::cout << "ScavTrap " << this->name <<  " attacks " << target << ", causing " \
		<< this->Attack_damage << " points of damage!" << std::endl;
		this->Energy_points--;
	}
}

void ScavTrap::guardGate(void) {
	if (!this->Hit_Points || !this->Energy_points) {
		std::cout << "ScavTrap " << this->name << "fainted and couldn't move...." << std::endl;
	}
	else {
		std::cout << "ScavTrap " << this->name << " has entered gate guard mode" << std::endl;
		this->Energy_points--;
	}
}

//ㄴㅐ일 와서 메인문 확인 및 실행.