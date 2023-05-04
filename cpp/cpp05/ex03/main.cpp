/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:08:45 by jaeywon           #+#    #+#             */
/*   Updated: 2023/05/04 21:52:40 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << std::endl;
	{
		Bureaucrat manto("manto", 3);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (!rrf)
			return 1;
		rrf->beSigned(manto);
		rrf->execute(manto);
		delete rrf;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		Bureaucrat manto("manto", 3);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "John");
		if (!rrf)
			return 1;
		rrf->beSigned(manto);
		rrf->execute(manto);
		delete rrf;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		Bureaucrat manto("manto", 3);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Roy");
		if (!rrf)
			return 1;
		rrf->beSigned(manto);
		rrf->execute(manto);
		delete rrf;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	// system("leaks intern");
	{
		Bureaucrat manto("manto", 3);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("abocado", "Sally");
		if (!rrf)
			return 1;
		rrf->beSigned(manto);
		rrf->execute(manto);
	}
	std::cout << std::endl;
	std::cout << std::endl;
	return 0;
}