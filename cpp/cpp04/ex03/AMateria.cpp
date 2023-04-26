/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:42:43 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/26 17:36:42 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
	
}

AMateria::AMateria(AMateria const& obj) {
	*this = obj;
}

AMateria::AMateria(std::string const& type) : type(type) {

}

AMateria::~AMateria() {

}

AMateria &AMateria::operator=(const AMateria &src) {
	if (this == &src)
		return (*this);
	type = src.type;
	return (*this);
}

std::string const &AMateria::getType() const {
	return (type);
}

void AMateria::use(ICharacter &target) {
	(void)target;
}