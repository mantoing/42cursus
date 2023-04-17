/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 06:13:49 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/17 22:03:32 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() 
{
	Animal *animal[10];

	for (int i = 0; i < 10; i++) {
		if (i < 5)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
		std::cout << std::endl;
	}
	for (int i = 0; i < 10; i++) {
		delete animal[i];
	}
    system("leaks ABrain");
    return 0; //메인문 추거허고 더 테스트 할것 없는지 확인해야한다.
}