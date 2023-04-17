/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:04:27 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/17 22:03:27 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal{
 private: 
	Brain *brain;
 public:
	Cat();
	Cat(const Cat& obj);
	~Cat();

	Cat& operator=(const Cat& obj);
	void makeSound() const;
};

#endif