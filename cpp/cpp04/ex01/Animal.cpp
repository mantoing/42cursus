/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:49:24 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/17 18:06:11 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal& obj){
	*this = obj;
	std::cout << "Type ( " << this->type << " ) Animal copy constructor is called" << std::endl;
}

Animal::~Animal(){
	std::cout << "Type ( " << this->type << " ) Animal destructor is called" << std::endl;
}

Animal &Animal::operator=(const Animal &obj) {
	std::cout << "Type ( " << this->type << " ) Animal copy assignment operator" << std::endl;
	if (this == &obj)
		return (*this);
	type = obj.type;
	return (*this);
}

void Animal::makeSound() const {
	std::cout << "default type animal can`t make sounds!" << std::endl;
}

std::string Animal::getType() const {
	return (type);
}