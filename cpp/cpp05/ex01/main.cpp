/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:08:45 by jaeywon           #+#    #+#             */
/*   Updated: 2023/05/22 20:26:42 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	std::cout << std::endl;
	std::cout << std::endl;
	{
		try{
			Bureaucrat jae("jae", 3);
			Form 		atom("atom", 15, 20);
			std::cout << jae << "signFrom => ";
			jae.signForm(atom);
		}catch (std::exception &error){
			std::cout << "ERROR!!" << std::endl;
			std::cout << error.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		try{
			Bureaucrat yun("yun", 3);
			Form 		atom("atom", 15, 20);
			std::cout << yun;
			yun.signForm(atom);
		}catch (std::exception &error){
			std::cout << "ERROR!!" << std::endl;
			std::cout << error.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	// system("leaks form");
	return 0;
}
