/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:50:21 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/10 16:24:20 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	prompt_start(void)
{
	std::cout << "Nice to meet you" << std::endl;
	std::cout << "This is your Phonbook" << std::endl;
	std::cout << "Input command" << std::endl;
	std::cout << "1. ADD" << std::endl;
	std::cout << "2. SEARCH" << std::endl;
	std::cout << "3. EXIT" << std::endl;
	
}

int main(void)
{
	std::string	cmd;
	PhoneBook pb;

	prompt_start();
	while (1)
	{
		cmd = "";
		std::getline(std::cin, cmd);
		if (std::cin.fail())
		{
			std::cout << "Wrong Input" << std::endl;
			exit(1);
		}
		if (cmd == "ADD")
			pb.add_info();
		else if (cmd == "SEARCH")
			pb.search_info();
		else if (cmd == "EXIT")
			break;
	}
	return (0);
}