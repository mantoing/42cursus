/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:10:41 by jaeywon           #+#    #+#             */
/*   Updated: 2023/05/25 15:56:04 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int	main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cout << "Please, put in two arguments!" << std::endl;
		return 1;
	}

	Convert	converter(argv[1]);
	converter.CheckChar();
	converter.CheckInt();
	converter.CheckFloat();
	converter.CheckDouble();
}