/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:13:24 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/26 17:42:11 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
 private:
	AMateria *sources[4];
 public:
	MateriaSource();
	MateriaSource(const MateriaSource& obj);
	~MateriaSource();
	MateriaSource& operator=(const MateriaSource& obj);

	void learnMateria(AMateria* materia);
	AMateria* createMateria(std::string const& type);
};

#endif