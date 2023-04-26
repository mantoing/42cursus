/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:17:18 by jaeywon           #+#    #+#             */
/*   Updated: 2023/04/26 17:45:31 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
	{
		sources[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &obj) {
	*this = obj;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
	{
		if (sources[i] != NULL)
			delete sources[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj) {
	if (this == &obj)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		sources[i] = obj.sources[i];
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *materia) {
	for (int i = 0; i < 4; i++) {
		if (sources[i] == NULL)
		{
			sources[i] = materia->clone();
			return ;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++)
	{
		if (sources[i] != NULL && sources[i]->getType() == type)
		{
			return (sources[i]->clone());
		}
	}
	return NULL;
}