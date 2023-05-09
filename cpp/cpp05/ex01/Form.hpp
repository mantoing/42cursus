/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:12:30 by jaeywon           #+#    #+#             */
/*   Updated: 2023/05/09 15:09:41 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form {
 private:
	const std::string name;
	bool	sign_check;
	const int grade_sign;
	const int grade_exe;

 public:
	class GradeTooHighException : public std::exception {
		public:
			const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			const char *what() const throw();
	};
	Form();
	Form(const Form& obj);
	Form(const std::string name, const int grade_sign, const int grade_exe);
	~Form();
	Form& operator=(const Form& obj);

	std::string getName() const;
	int getGrade_sign() const;
	int getGrade_exe() const;
	bool getSign_check() const;
	void	beSigned(const Bureaucrat &obj);
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif