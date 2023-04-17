/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:17:02 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/17 17:44:16 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>


class WrongAnimal {
 protected:
	std::string type;
 public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& obj);
	~WrongAnimal();
	WrongAnimal& operator=(const WrongAnimal& obj);
	void makeSound(void) const;
	std::string getType() const;
};

#endif
