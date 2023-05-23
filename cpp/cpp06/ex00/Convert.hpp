/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:10:38 by jaeywon           #+#    #+#             */
/*   Updated: 2023/05/23 17:00:17 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <limits>
# include <iomanip>

class Convert {
 private:
	const std::string _value;
	double _double;
 public:
	Convert();
	Convert(std::string _value);
	Convert(const Convert& obj);
	~Convert();
	Convert& operator=(const Convert& obj);

	void CheckInt() const;
	void CheckChar() const;
	void CheckDouble() const;
	void CheckFloat() const;

	bool is_char(std::string value) const;

};

#endif
