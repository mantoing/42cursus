/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:08:12 by jaeywon           #+#    #+#             */
/*   Updated: 2023/05/09 15:08:20 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
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
	class ExecuteFailedException : public std::exception {
		public:
			const char * what() const throw();
	};
	class CheckSigned : public std::exception {
		public:
			const char * what() const throw();
	};
	AForm();
	AForm(const AForm& obj);
	AForm(const std::string name, const int grade_sign, const int grade_exe);
	virtual ~AForm();
	AForm& operator=(const AForm& obj);

	std::string getName() const;
	int getGrade_sign() const;
	int getGrade_exe() const;
	bool getSign_check() const;
	
	void	beSigned(const Bureaucrat &obj);
	virtual void execute(Bureaucrat const & excutor) const = 0;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif