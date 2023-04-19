/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:07:06 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/19 19:12:53 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <iostream>


class  DiamondTrap : public FragTrap, public ScavTrap {
 private:
	std::string name;
 public:
	 DiamondTrap();
	 DiamondTrap(std::string name);
	 DiamondTrap(const DiamondTrap& diamond);
	~ DiamondTrap();
	 DiamondTrap& operator=(const  DiamondTrap& obj);
	 void whoAmI(void);
	 void printStatus(void);
};

#endif