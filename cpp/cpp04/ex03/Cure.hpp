/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:04:22 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/24 22:04:41 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"


class Cure : public AMateria{
 public:
	Cure();
	Cure(const Cure& obj);
	virtual ~Cure();
	Cure& operator=(const Cure& obj);

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif