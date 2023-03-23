/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:02:57 by jaeywon           #+#    #+#             */
/*   Updated: 2023/03/23 18:33:57 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int print_error(std::string str){
	std::cout << str << std::endl;
	return (1);
}

int main(int ac, char **av){
	Sed	sed;

	if (ac != 4 || std::strlen(av[1]) == 0)
		return (print_error("argument error"));
	sed.set_file(av[1]);
	sed.set_s1(av[2]);
	sed.set_s2(av[3]);
	sed.change_s1_to_s2();
	return (0);
}