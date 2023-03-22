/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:16:37 by jaeywon           #+#    #+#             */
/*   Updated: 2023/03/22 14:40:19 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
private:
	std::string name;
public:
	Zombie(std::string name);
	~Zombie(void);
	void	announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif