/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 06:13:49 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/17 18:20:52 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;
	std::cout << "----------Wrong test------------" << std::endl;
	const WrongAnimal* wani = new WrongAnimal();
	const WrongAnimal* wcat = new WrongCat();
	std::cout << wani->getType() << " " << std::endl;
	std::cout << wcat->getType() << " " << std::endl;
	wani->makeSound();
	wcat->makeSound();
	delete (wani);
	delete (wcat);
	// wcat will say "WrongAnimal sound~" because WrongAnimal' makeSound is not virtual function

	system("leaks Animal");
	return (0);
}