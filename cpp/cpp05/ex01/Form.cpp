/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:24:58 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/28 22:04:01 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name(""), sign_check(false), grade_sign(150), grade_exe(150) {
	
}

Form::Form(const std::string name, const int grade_sign, const int grade_exe)
	: name(name), grade_exe(150), grade_sign(150), sign_check(false) {
		if (grade_sign < 1 || grade_exe < 1)
			throw Form::GradeTooHighException();
		if (grade_sign < 150 || grade_exe < 150)
			throw Form::GradeTooLowException();
}

Form::Form(const Form& obj) : name(obj.name), grade_sign(obj.grade_sign), grade_exe(obj.getGrade_exe){
	*this = obj;
}

Form::~Form() {
	
}

Form& Form::operator=(const Form& obj) {
	sign_check = obj.sign_check;
	return (*this);
}

int Form::std::string getName() const {
	return (name);
}

int Form::getGrade_sign() const {
	return (grade_sign);
}

int Form::getGrade_exe() const {
	return (grade_exe);
}

bool Form::getSign_check() const {
	return (sign_check);
}

void Form::beSigned(const Bureaucrat &obj) {
	if (obj.getGrade() > grade_sign)
		throw Form::GradeTooLowException();
	sign_check = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &o, const Form &i) {
	o << "name : " << i.getName() << std::endl << "Grade to sign : " << i.getGrade_sign()
	<< std::endl << "Grade to execute : " << i.getGrade_exe() << std::endl;
	return o;
}