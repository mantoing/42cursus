/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:03:10 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/17 22:03:10 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	type = "WrongCat";
	std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj){
	*this = obj;
	std::cout << "Type ( " << this->type << " ) WrongCat copy constructor is called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "Type ( " << this->type << " ) WrongCat destructor is called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &obj) {
	std::cout << "Type ( " << this->type << " ) WrongCat copy assignment operator" << std::endl;
	if (this == &obj)
		return (*this);
	type = obj.type;
	return (*this);
}

void WrongCat::makeSound() const {
	std::cout << "Meow Meow ~ " << std::endl;
}