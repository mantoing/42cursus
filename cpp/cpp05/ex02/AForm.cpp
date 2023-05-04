/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:24:58 by jaeywon           #+#    #+#             */
/*   Updated: 2023/05/04 16:43:58 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name(""), sign_check(false), grade_sign(150), grade_exe(150) {
	
}

AForm::AForm(const std::string name, const int grade_sign, const int grade_exe)
	: name(name), sign_check(false), grade_sign(grade_sign), grade_exe(grade_exe){
		if (grade_sign < 1 || grade_exe < 1)
			throw AForm::GradeTooHighException();
		if (grade_sign > 150 || grade_exe > 150)
			throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& obj) : name(obj.name), grade_sign(obj.grade_sign), grade_exe(obj.grade_exe){
	*this = obj;
}

AForm::~AForm() {
	
}

AForm& AForm::operator=(const AForm& obj) {
	sign_check = obj.sign_check;
	return (*this);
}

std::string AForm::getName() const {
	return (name);
}

int AForm::getGrade_sign() const {
	return (grade_sign);
}

int AForm::getGrade_exe() const {
	return (grade_exe);
}

bool AForm::getSign_check() const {
	return (sign_check);
}

void AForm::beSigned(const Bureaucrat &obj) {
	if (obj.getGrade() > grade_sign)
		throw AForm::GradeTooLowException();
	sign_check = true;
}

const char* AForm::ExecuteFailedException::what() const throw() {
	return ("Execute failed.. plz check the grade.");
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

const char* AForm::CheckSigned::what() const throw() {
	return ("signed is false! check Breaucrat`s sign");
}

std::ostream &operator<<(std::ostream &o, const AForm &i) {
	o << "name : " << i.getName() << std::endl << "Grade to sign : " << i.getGrade_sign()
	<< std::endl << "Grade to execute : " << i.getGrade_exe() << std::endl;
	return o;
}