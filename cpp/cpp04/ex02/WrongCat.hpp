/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:03:50 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/17 22:03:50 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{

 public:
	WrongCat();
	WrongCat(const WrongCat& obj);
	~WrongCat();

	WrongCat& operator=(const WrongCat& obj);
	void makeSound() const;
};

#endif