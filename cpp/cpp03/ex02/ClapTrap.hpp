/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:50:40 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/05 22:08:52 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>


class ClapTrap {
 protected:
	std::string name;
	unsigned int Hit_Points;
	unsigned int Energy_points;
	unsigned int Attack_damage;
 public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& src);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap& src);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif