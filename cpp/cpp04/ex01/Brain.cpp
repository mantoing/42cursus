/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:02:40 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/17 22:02:41 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain& obj) {
	*this = obj;
	std::cout << "Brain copy constructor is called" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain	&Brain::operator=(const Brain& obj){
	std::cout << "Brain copy assignment operator" << std::endl;
	if (this == &obj)
		return (*this);
	for(int i=0; i < 100; i++) {
		ideas[i] = obj.ideas[i];
	}
	return (*this);
}