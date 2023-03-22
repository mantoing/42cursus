/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:15:46 by jaeywon           #+#    #+#             */
/*   Updated: 2023/03/22 20:20:52 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon{
	private:
		std::string type;
	public:
		const	std::string &getType(void);
		void	setType(std::string type);
		Weapon(void);
		Weapon(std::string type);
};

#endif