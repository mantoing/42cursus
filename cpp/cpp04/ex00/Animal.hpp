/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 06:14:06 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/13 15:14:03 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>


class Animal {
 protected:
	std::string type;
 public:
	Animal();
	Animal(const Animal& obj);
	virtual ~Animal();
	Animal& operator=(const Animal& obj);
	virtual void makeSound(void) const;
	std::string getType() const;
};

#endif
