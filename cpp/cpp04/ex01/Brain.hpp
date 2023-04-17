/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:02:46 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/17 22:02:46 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
 private:
	std::string ideas[100];
 public:
	Brain();
	Brain(const Brain& obj);
	~Brain();
	
	Brain& operator=(const Brain& obj);
};

#endif
