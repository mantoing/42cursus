/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:08:04 by jaeywon           #+#    #+#             */
/*   Updated: 2023/05/09 15:08:04 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {

}

Intern::Intern(const Intern& obj) {
	*this = obj;
}

Intern::~Intern() {

}

Intern &Intern::operator=(const Intern& obj){
	(void)obj;
	return (*this);
}

AForm *Intern::makeForm(std::string  name, std::string target) {
	std::string names[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	int i;

	for (i = 0; i < 3; i ++) {
		if (name == names[i]) {
			break;
		}
	}
	if (i < 3)
		std::cout << "Intern creates " << target << std::endl;
	switch (i)
	{
		case 0:
			return (new RobotomyRequestForm(target));
		case 1:
			return new PresidentialPardonForm(target);
		case 2:
			return new ShrubberyCreationForm(target);
		default:
			std::cout << name << " is not part of forms!" << std::endl;
			std::cout << "Intern can't create " << target << std::endl;
			break;
	}
	return NULL;
}