/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:24:28 by jaeywon           #+#    #+#             */
/*   Updated: 2023/03/22 21:32:51 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {
 private:
	std::string name;
	Weapon *weapon;
 public:
	HumanB(std::string name);
	void setWeapon(Weapon &weapon);
	void attack(void);
};
#endif