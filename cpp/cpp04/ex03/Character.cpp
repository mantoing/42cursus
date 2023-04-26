/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:01:14 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/26 17:50:52 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("character"){
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(std::string name) : name(name) {
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character& obj) {
	*this = obj;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
	}
}

Character &Character::operator=(const Character &obj) {
	if (this == &obj)
		return (*this);
	name = obj.name;
	for (int i = 0; i < 4; i++)
		inventory[i] = obj.inventory[i];
	return (*this);
}

std::string const &Character::getName() const {
	return (name);
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return;
	if (inventory[idx] == NULL)
	{
		return ;
	}
	delete inventory[idx];
	inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (inventory[idx] == NULL)
		return ;
	inventory[idx]->use(target);
}