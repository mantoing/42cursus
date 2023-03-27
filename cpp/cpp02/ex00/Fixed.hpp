/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:18:16 by jaeywon           #+#    #+#             */
/*   Updated: 2023/03/27 16:18:22 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
 private:
	int	value;
	static const int	bits = 8;

 public:
	Fixed();
	Fixed(const Fixed& src);
	~Fixed();
	Fixed& operator=(const Fixed& src);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
