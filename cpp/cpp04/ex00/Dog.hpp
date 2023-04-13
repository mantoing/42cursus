/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:12:52 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/13 15:14:34 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"


class Dog : public Animal{

 public:
	Dog();
	Dog(const Dog& obj);
	~Dog();
	
	Dog& operator=(const Dog& obj);
	void makeSound() const;
};

#endif