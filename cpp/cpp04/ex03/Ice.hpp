/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:55:32 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/24 21:59:12 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"


class Ice : public AMateria{
 public:
	Ice();
	Ice(const Ice& obj);
	virtual ~Ice();
	Ice& operator=(const Ice& obj);

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif