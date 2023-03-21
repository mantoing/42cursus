/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:33:14 by jaeywon           #+#    #+#             */
/*   Updated: 2023/03/21 22:14:36 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int PhoneBook::num = -1;
int PhoneBook::full_flag = 0;

std::string	PhoneBook::readline_handle(){
	std::string line;

	std::getline(std::cin, line);
	if (std::cin.fail())
	{
		std::cout << "Invalid Input" << std::endl;
		exit(1);
	}
	if (line.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ") != std::string::npos)
	{
		std::cout << "Invalid Input" << std::endl;
		return ("");
	}
	return line;
}


void	PhoneBook::add_info(void)
{
	PhoneBook	pb;
	std::string value;

	num++;
	if (num > 7)
	{
		num = 0;
		full_flag = 1;
	}
	std::cout << "Plz Add new List Number < " << num << " >" << std::endl;
	std::cout << "First Name : ";
	value = readline_handle();
	if (value == "")
	{
		std::cout << "Invalid Input" << std::endl;
		num--;
		return ;
	}
	contact[num].set_f_name(value);
	std::cout << "Last Name : ";
	value = readline_handle();
	if (value == "")
	{
		std::cout << "Invalid Input" << std::endl;
		num--;
		return ;
	}
	contact[num].set_l_name(value);
	std::cout << "Nickname : ";
	value = readline_handle();
	if (value == "")
	{
		std::cout << "Invalid Input" << std::endl;
		num--;
		return ;
	}
	contact[num].set_n_name(value);
	std::cout << "Phone Number : ";
	value = readline_handle();
	if (value == "")
	{
		std::cout << "Invalid Input" << std::endl;
		num--;
		return ;
	}
	contact[num].set_p_num(value);
	std::cout << "Darkest Secret : ";
	value = readline_handle();
	if (value == "")
	{
		std::cout << "Invalid Input" << std::endl;
		num--;
		return ;
	}
	contact[num].set_secret(value);
	std::cout << "List Number< " << num << " > has been successfully finished" << std::endl;	
}

void	PhoneBook::search_info(void)
{
	int n;
	std::string input;
	int idx;

	if (num == -1)
	{
		std::cout << "your PhoneBook is empty" << std::endl;
		return ;
	}
	if (full_flag == 1)
		n = 7;
	else
		n = num;
	std::cout << std::setw(10) <<" index" << "|" << std::setw(10) << "first name" << "|" << \
		std::setw(10) << "last name" << "|" << std::setw(10) << "nickname" << "|" << std::endl;
	for(int i = 0; i <= n; i++)
		contact[i].print_short(i);
	std::cout << "Pick the number you want to check" << std::endl;
	std::cout << "Number : ";
	std::getline(std::cin, input);
	if (std::cin.fail())
	{
		std::cout << "Invalid Input" << std::endl;
		exit(1);
	}
	idx = (int)(input[0] - '0');
	if (input[1] || !(idx >= 0 && idx <= n)){
		std::cout << "This PhoneBook can only store 0 to 7 or Invalid input" << std::endl;
		return ;
	}
	std::cout << "Search result" << std::endl;
	std::cout << "*********************************************" << std::endl;
	contact[idx].print_list_info();
}