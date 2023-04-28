/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:08:45 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/27 19:12:02 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
  	std::cout << "-----Test#0 constructor grade too high-----" << std::endl;
  	{
    	try {
      		Bureaucrat b("Bureaucrat", 0);
    	} catch (std::exception &e) {
    		std::cout << e.what() << std::endl;
    	}
	}
	std::cout << std::endl;

	std::cout << "-----Test#1 constructor grade too low-----" << std::endl;
	{
		try {
			Bureaucrat b("Bureaucrat", 151);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "-----Test#2 increment()-----" << std::endl;
	{
		try {
    		Bureaucrat b("Bureaucrat", 9);
    		std::cout << b;
    		for (int i = 0; i < 10; i++) {
    			b.increment();
       		 	std::cout << b;
    		}
   		} catch (std::exception &e) {
    		std::cout << e.what() << std::endl;
    	}
	}
	std::cout << std::endl;

	std::cout << "-----Test#3 decrement()-----" << std::endl;
	{
		try {
			Bureaucrat b("Bureaucrat", 141);
			std::cout << b;
			for (int i = 0; i < 10; i++) {
				b.decrement();
				std::cout << b;
			}
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	return 0;
}