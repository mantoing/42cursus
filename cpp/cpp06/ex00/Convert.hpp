/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:10:38 by jaeywon           #+#    #+#             */
/*   Updated: 2023/05/25 16:17:56 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <limits>
# include <iomanip>

class Convert {
 private:
	static const std::string _value;
	static double _double;
	Convert();
 public:
	Convert(std::string _value);
	Convert(const Convert& obj);
	~Convert();
	Convert& operator=(const Convert& obj);

	static void CheckInt();
	static void CheckChar();
	static void CheckDouble();
	static void CheckFloat();

	static bool is_char(std::string value);

};

#endif
