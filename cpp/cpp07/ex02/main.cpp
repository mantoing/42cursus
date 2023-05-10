/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:59:46 by jaeywon           #+#    #+#             */
/*   Updated: 2023/05/10 21:54:04 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 5

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
		// std::cout << numbers[0] << std::endl;
		// std::cout << tmp[0] << std::endl;
		// std::cout << test[0] << std::endl << std::endl;
		// int temp = numbers[0];
		// numbers[0] = 1;
		// std::cout << numbers[0] << std::endl;
		// std::cout << tmp[0] << std::endl;
		// std::cout << test[0] << std::endl << std::endl;
		// numbers[0] = temp;
		for (int j = 0; j < MAX_VAL; j++)
		{
			std::cout << "number[" << j << "] : " << numbers[j] << std::endl;
		}
		for (int k = 0; k < MAX_VAL; k++)
		{
			std::cout << "mirror[" << k << "] : " << mirror[k] << std::endl;
		}
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    // try
    // {
    //     numbers[-2] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // try
    // {
    //     numbers[MAX_VAL] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     numbers[i] = rand();
    // }

    delete [] mirror;
    return 0;
}