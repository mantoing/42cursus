/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:07:32 by jaeywon           #+#    #+#             */
/*   Updated: 2023/05/09 15:07:33 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("ppf", 25, 5), target("") {

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("ppf", 25, 5), target(target) {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj) {
	*this = obj;
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
	target = obj.getTarget();
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const {
	return (target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!(this->getSign_check()))
		throw CheckSigned();
	else if (executor.getGrade() > this->getGrade_exe())
		throw ExecuteFailedException();
	else {
		std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
}

std::ostream &operator<<(std::ostream &o, const PresidentialPardonForm &i) {
	o << "name : " << i.getName() << std::endl << "Grade to sign : " << i.getGrade_sign()
	<< std::endl << "Grade to execute : " << i.getGrade_exe() << std::endl;
	return o;
}