/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:06:03 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/17 22:03:26 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat& obj){
	*this = obj;
	brain = new Brain();
	std::cout << "Type ( " << this->type << " ) Cat copy constructor is called" << std::endl;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Type ( " << this->type << " ) Cat destructor is called" << std::endl;
}

Cat &Cat::operator=(const Cat &obj) {
	std::cout << "Type ( " << this->type << " ) Cat copy assignment operator" << std::endl;
	if (this == &obj)
		return (*this);
	type = obj.type;
	*brain = *(obj.brain);
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "Meow Meow ~ " << std::endl;
}