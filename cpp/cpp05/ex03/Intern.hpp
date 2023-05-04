#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
 public:
	Intern();
	Intern(const Intern& obj);
	~Intern();
	Intern& operator=(const Intern& obj);

	AForm *makeForm(std::string form, std::string target);
};

#endif
