/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:03:43 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/17 22:03:43 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj){
	*this = obj;
	std::cout << "Type ( " << this->type << " ) WrongAnimal copy constructor is called" << std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "Type ( " << this->type << " ) WrongAnimal destructor is called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj) {
	std::cout << "Type ( " << this->type << " ) WrongAnimal copy assignment operator" << std::endl;
	if (this == &obj)
		return (*this);
	type = obj.type;
	return (*this);
}

void WrongAnimal::makeSound() const {
	std::cout << "default type animal can`t make sounds!" << std::endl;
}

std::string WrongAnimal::getType() const {
	return (type);
}