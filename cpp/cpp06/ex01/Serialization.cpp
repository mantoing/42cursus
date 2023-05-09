/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:10:52 by jaeywon           #+#    #+#             */
/*   Updated: 2023/05/09 15:10:52 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization() {

}

Serialization::Serialization(const Serialization& obj) {
	*this = obj;
}

Serialization::~Serialization() {

}

Serialization &Serialization::operator=(const Serialization& obj){
	if (this == &obj)
		return (*this);
	return (*this);
}

uintptr_t Serialization::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serialization::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}