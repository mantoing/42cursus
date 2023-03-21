/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:48:19 by jaeywon           #+#    #+#             */
/*   Updated: 2023/03/21 21:06:58 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::print_list_info(void){
	std::cout << "Fitst Name : " << this->first_name << std::endl;
	std::cout << "Last Name : " << this->last_name << std::endl;
	std::cout << "Nickname : " << this->nickname << std::endl;
	std::cout << "Phone Number : " << this->phone_number << std::endl;
	std::cout << "Darkest Secret : " << this->secret << std::endl;
	std::cout << "*********************************************" << std::endl;
}

std::string	Contact::count_input(std::string data){
	if (data.length() >= 10)
		data = data.substr(0, 9).append(".");
	return (data);
}

void	Contact::print_short(int num){
	std::cout << std::setw(10) << num << "|";
	std::cout << std::setw(10) << count_input(first_name) << "|";
	std::cout << std::setw(10) << count_input(last_name) << "|";
	std::cout << std::setw(10) << count_input(nickname) << "|" << std::endl;
}

void	Contact::set_f_name(std::string first_name){
	this->first_name = first_name;
}

void	Contact::set_l_name(std::string last_name){
	this->last_name = last_name;
}

void	Contact::set_n_name(std::string nickname){
	this->nickname = nickname;
}

void	Contact::set_p_num(std::string phone_number){
	this->phone_number = phone_number;
}

void	Contact::set_secret(std::string secret){
	this->secret = secret;
}
