/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:08:45 by jaeywon           #+#    #+#             */
/*   Updated: 2023/05/04 21:29:30 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(){
	std::cout << std::endl;
	std::cout << std::endl;
	{
		try{
			Bureaucrat 					manto("manto", 3);
			// Bureaucrat 					manto("manto", 50);
			PresidentialPardonForm 		pizza("pizza");
			manto.signForm(pizza);
			manto.executeForm(pizza);
		}catch (std::exception &error){
			std::cout << "ERROR!!" << std::endl;
			std::cout << error.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		try{
			Bureaucrat 			jaeyun("jaeyun", 28);
			// Bureaucrat 			jaeyun("jaeyun", 50);
			RobotomyRequestForm 	pizza("pizza");
			jaeyun.signForm(pizza);
			jaeyun.executeForm(pizza);
		}catch (std::exception &error){
			std::cout << "ERROR!!" << std::endl;
			std::cout << error.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		try{
			Bureaucrat 			won("won", 82);
			// Bureaucrat 			won("won", 140);
			ShrubberyCreationForm 		pizza("pizza");
			won.signForm(pizza);
			won.executeForm(pizza);
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