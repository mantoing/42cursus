/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:58:22 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/26 17:27:33 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() {
	this->type = "ice";
}

Ice::Ice( const Ice& obj) {
	*this = obj;
}

Ice::~Ice() {
	
}

Ice &Ice::operator=(Ice const &obj) {
	if (this == &obj)
		return (*this);
	type = obj.type;
	return (*this);
}

AMateria *Ice::clone() const {
	return (new Ice());
}

void Ice::use(ICharacter &target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}