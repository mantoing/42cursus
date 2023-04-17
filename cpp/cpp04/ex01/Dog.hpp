/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:12:52 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/17 20:52:07 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"


class Dog : public Animal{
 private:
	Brain *brain;
 public:
	Dog();
	Dog(const Dog& obj);
	~Dog();
	
	Dog& operator=(const Dog& obj);
	void makeSound() const;
};

#endif