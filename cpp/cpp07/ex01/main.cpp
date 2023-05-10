/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:55:45 by jaeywon           #+#    #+#             */
/*   Updated: 2023/05/10 19:58:28 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	std::string array1[3] = {"hello", "world", "jaeywon"};
	int array2[3] = {10, 20, 30};

	iter(array1, 3, print);
	iter(array2, 3, print);
	return (0);
}