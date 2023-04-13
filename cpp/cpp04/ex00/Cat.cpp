/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:06:03 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/13 15:12:31 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat& obj){
	*this = obj;
	std::cout << "Type ( " << type << " ) Cat copy constructor is called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Type ( " << type << " ) Cat destructor is called" << std::endl;
}

Cat &Cat::operator=(const Cat &obj) {
	std::cout << "Type ( " << type << " ) Cat copy assignment operator" << std::endl;
	if (this == &obj)
		return (*this);
	type = obj.type;
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "Meow Meow ~ " << std::endl;
}