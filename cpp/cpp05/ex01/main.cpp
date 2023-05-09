/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:08:45 by jaeywon           #+#    #+#             */
/*   Updated: 2023/05/09 15:09:38 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	std::cout << std::endl;
	std::cout << std::endl;
	{
		try{
			Bureaucrat seok("seok", 3);
			Form 		atom("atom", 15, 20);
			std::cout << seok << "signFrom => ";
			seok.signForm(atom);
		}catch (std::exception &error){
			std::cout << "ERROR!!" << std::endl;
			std::cout << error.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		try{
			Bureaucrat choi("choi", 18);
			Form 		atom("atom", 15, 20);
			std::cout << choi;
			choi.signForm(atom);
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
