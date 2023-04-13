/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:30:14 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/12 20:30:15 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() {
	this->name = "";
	this->Hit_Points = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
	std::cout << "FragTrap Constructor(Default) called" << std::endl;
}

FragTrap::FragTrap(std::string _name): ClapTrap(_name) {
	this->name = _name;
	this->Hit_Points = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
	std::cout << "FragTrap Constructor("<< this->name << ") called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src){
	this->name = src.name;
	this->Hit_Points = src.Hit_Points;
	this->Energy_points = src.Energy_points;
	this->Attack_damage = src.Attack_damage;
	std::cout << "FragTrap copy Constructor("<< this->name << ") called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const& frag){
	this->name = frag.name;
	this->Hit_Points = frag.Hit_Points;
	this->Energy_points = frag.Energy_points;
	this->Hit_Points = frag.Hit_Points;
	std::cout << "FragTrap Constructor("<< this->name << ") called" << std::endl;
	return (*this);
}

void FragTrap::highFivesGuys(void) {
	if (!this->Hit_Points || !this->Energy_points) {
		std::cout << "FragTrap " << this->name << "fainted and couldn't move...." << std::endl;
	}
	else {
		std::cout << "FragTrap " << this->name << " high five!" << std::endl;
	}
}
