/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:44:17 by jaeywon           #+#    #+#             */
/*   Updated: 2023/05/09 15:09:51 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//------constructor-------//

Bureaucrat::Bureaucrat() : name(""), grade(150){
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) {
	*this = obj;
}

// ------destructor-----//
Bureaucrat::~Bureaucrat() {
}

//-------operator------//
Bureaucrat &Bureaucrat::operator=(const Bureaucrat& obj) {
	if (this == &obj)
		return (*this);
	grade = obj.getGrade();
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i){
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << "." << std::endl;
	return (o);
}

//-------accessor-------//
const std::string Bureaucrat::getName(void) const {
	return (name);
}

int	Bureaucrat::getGrade(void) const {
	return (grade);
}

//--------methods-------//
void Bureaucrat::increment(void) {
	if (grade == 1)
		throw GradeTooHighException();
	grade = grade -1;
}

void Bureaucrat::decrement(void) {
	if (grade == 150)
		throw GradeTooLowException();
	grade = grade + 1;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

void Bureaucrat::signForm(Form &form)
{
	try {
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	} catch (const std::exception &err) {
		std::cout << getName() << " couldn't sign " << form.getName()
		<< " because " << err.what() << std::endl;
	}
}