/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:56:49 by jaeywon           #+#    #+#             */
/*   Updated: 2023/03/23 18:22:28 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>

class Sed{
	private:
		std::ifstream ifs;
		std::ofstream ofs;
		std::string in_file;
		std::string out_file;
		std::string s1;
		std::string s2;
	public:
		void	set_file(std::string fname);
		void	set_s1(std::string s1);
		void	set_s2(std::string s2);
		void	change_s1_to_s2(void);
};

#endif