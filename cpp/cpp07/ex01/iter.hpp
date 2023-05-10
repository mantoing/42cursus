/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:35:36 by jaeywon           #+#    #+#             */
/*   Updated: 2023/05/10 19:55:39 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T *array, int len, void (*f)(T &a))
{
	for (int i = 0; i < len; i++)
	{
		(*f)(array[i]);
	}
}

template <typename T>
void print(T &a)
{
	std::cout << a << std::endl;
}

#endif