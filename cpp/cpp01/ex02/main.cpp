/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:31:52 by jaeywon           #+#    #+#             */
/*   Updated: 2023/03/22 16:40:54 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void){
	std::string	str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Memory address" << std::endl;
	std::cout << "str address       = " << &str << std::endl;
	std::cout << "stringPTR address = " << stringPTR << std::endl;
	std::cout << "stringREF address = " << &stringREF << std::endl;

	std::cout << std::endl;
	std::cout << "Memory Value" << std::endl;
	std::cout << "str Value       = " << str << std::endl;
	std::cout << "stringPTR Value = " << *stringPTR << std::endl;
	std::cout << "stringREF Value = " << stringREF << std::endl;

	return (0);
}