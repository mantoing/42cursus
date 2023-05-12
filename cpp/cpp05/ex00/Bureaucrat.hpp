/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:48:01 by jaeywon           #+#    #+#             */
/*   Updated: 2023/05/12 20:05:06 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat {
 private:
	const std::string name;
	int	grade;

 public:
	class GradeTooHighException : public std::exception {
		public:
			const char *what() const throw();
	}; // try catch문을 사용하기에 앞서 필요한 예외 처리 부분을 처리해 주기 위해 what()문 설정
	class GradeTooLowException : public std::exception {
		public:
			const char *what() const throw();
	}; // try catch문을 사용하기에 앞서 필요한 예외 처리 부분을 처리해 주기 위해 what()문 설정
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& obj);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& obj);

	const std::string getName(void) const;
	int getGrade(void) const;

	void	increment(void);
	void	decrement(void);
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif