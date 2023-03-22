/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:33:03 by jaeywon           #+#    #+#             */
/*   Updated: 2023/03/22 15:56:49 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
	std::string name;

public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);
	void	announce(void);
	void	setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif