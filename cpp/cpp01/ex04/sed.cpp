/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:01:23 by jaeywon           #+#    #+#             */
/*   Updated: 2023/03/23 18:44:43 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

void	Sed::set_file(std::string fname){
	in_file = fname;

	ifs.open(in_file);
	if (ifs.fail()){
		std::cout << "Cannot open" << std::endl;
		exit(1);
	}
	out_file = in_file.append(".replce");
}

void	Sed::set_s1(std::string s1){
	if (s1.length() == 0){
		std::cout << "s1 is empty" << std::endl;
		exit(1);
	}
	this->s1 = s1;
}

void	Sed::set_s2(std::string s2){
	if (s2.length() == 0){
		std::cout << "s2 is empty" << std::endl;
		exit(1);
	}
	this->s2 = s2;
}

void	Sed::change_s1_to_s2(void){
	std::string line;

	ofs.open(out_file);
	if (ofs.fail()){
		std::cout << "Cannot open ofs" << std::endl;
		exit(1);
	}
	while(true){
		std::getline(ifs, line);
		size_t pos = 0;
		while(true){
			pos = line.find(s1, pos);
			if (pos == std::string::npos)
				break;
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		ofs << line;
		if (ifs.eof())
			break;
		ofs << std::endl;
	}
}