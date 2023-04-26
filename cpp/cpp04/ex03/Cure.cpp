/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:05:13 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/26 17:47:53 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	
}

Cure::Cure(const Cure &obj) : AMateria(obj) {
	
}

Cure::~Cure() {}

Cure &Cure::operator=(const Cure &obj)
{
	if (this == &obj)
		return (*this);
	type = obj.type;
	return (*this);
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}