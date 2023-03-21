/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:52:56 by jaeywon           #+#    #+#             */
/*   Updated: 2023/03/21 20:48:39 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact {

public:
	void	print_list_info(void);
	void	set_f_name(std::string first_name);
	void	set_l_name(std::string last_name);
	void	set_n_name(std::string nickname);
	void	set_p_num(std::string phone_number);
	void	set_secret(std::string secret);
	void	print_short(int data);
	std::string count_input(std::string data);

private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string secret;
};

#endif