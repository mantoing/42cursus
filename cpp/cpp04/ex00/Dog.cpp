/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:14:42 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/13 15:16:26 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog& obj){
	*this = obj;
	std::cout << "Type ( " << type << " ) Dog copy constructor is called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Type ( " << type << " ) Dog destructor is called" << std::endl;
}

Dog &Dog::operator=(const Dog &obj) {
	std::cout << "Type ( " << type << " ) Dog copy assignment operator" << std::endl;
	if (this == &obj)
		return (*this);
	type = obj.type;
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "Woof! Woof!" << std::endl;
}