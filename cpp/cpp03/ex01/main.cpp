/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:32:38 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/08 03:25:25 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int	main( void )
{
	ScavTrap st("scavtrap");
	ClapTrap ct("claptrap");

	st.attack("kimchi");

	ct.takeDamage(6);
	ct.beRepaired(4);
	ct.takeDamage(3);
	ct.beRepaired(8);
	ct.takeDamage(42);
	std::cout << std::endl;

	st.takeDamage(6);
	st.beRepaired(4);
	st.takeDamage(3);
	st.beRepaired(8);
}