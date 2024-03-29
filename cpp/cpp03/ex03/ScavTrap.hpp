/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:56:10 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/12 22:20:03 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>


class ScavTrap: virtual public ClapTrap{
 public:
	ScavTrap();
	ScavTrap(std::string _name);
	~ScavTrap();
	ScavTrap(const ScavTrap& src);
	ScavTrap& operator=(const ScavTrap& scav);
	void attack(const std::string& target);
	void guardGate();
};

#endif