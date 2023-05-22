/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:06:19 by jaeywon           #+#    #+#             */
/*   Updated: 2023/05/17 21:06:19 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int n) {
	typename T::iterator res;
	
	res = std::find(container.begin(), container.end(), n);
	if (res == container.end())
		throw std::runtime_error("Not in this container");
	return (res);
}

#endif