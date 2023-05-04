#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <fstream>


class Bureaucrat;

class ShrubberyCreationForm : public AForm {
 private:
	std::string target;
 public:

	class FailOpenFile : public std::exception {
		public:
			const char* what() const throw();
	};
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& obj);
	~ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);

	std::string getTarget() const;
	void	execute(Bureaucrat const & executor) const;
};
std::ostream &operator<<(std::ostream &o, const ShrubberyCreationForm &i);

#endif
