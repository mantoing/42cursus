/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:51:25 by jaeywon           #+#    #+#             */
/*   Updated: 2023/02/14 19:57:27 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook{
	
private:
	Cotact	contact[8];
	static int num;
	static bool full;
	
public:
	Phonebook(/* args */);
	~Phonebook();

Phonebook::Phonebook(/* args */)
{
}

Phonebook::~Phonebook()
{
}


#endif