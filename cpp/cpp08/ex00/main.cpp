/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:06:22 by jaeywon           #+#    #+#             */
/*   Updated: 2023/05/17 21:06:25 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>


#include "easyfind.hpp"

int main()
{
	try {
		std::vector<int>	v(3);
		v[0] = 1;
		v[1] = 2;
		v[2] = 3;
		std::vector<int>::iterator i = easyfind(v, 3);
		std::cout << *i << std::endl;
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::deque<int>		d(3);
		d[0] = 5;
		d[1] = 3;
		d[2] = 2;
		std::deque<int>::iterator i = easyfind(d, 5);
		std::cout << *i << std::endl;
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::list<int>		l(100, 28);
		std::list<int>::iterator i = easyfind(l, 29);
		std::cout << *i << std::endl;
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}