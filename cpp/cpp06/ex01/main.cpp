/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:10:47 by jaeywon           #+#    #+#             */
/*   Updated: 2023/05/09 15:10:48 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main(int ac, char *av[])
{
	Data prev;
	Data *next;
	uintptr_t ptr;

	if (ac != 2)
	{
		std::cout << "argument count is not 2" << std::endl;
		return (1);
	}	
	prev.name = av[1];
	std::cout << "prev : " << prev.name << std::endl;

	ptr = Serialization::serialize(&prev);
	std::cout << "ptr : " << ptr << std::endl;

	next = Serialization::deserialize(ptr);
	std::cout << "next : " << next->name << std::endl;

	return (0);
}