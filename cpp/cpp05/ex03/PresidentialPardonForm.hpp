#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm{
 private:
	std::string target;
 public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& obj);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);

	std::string getTarget() const;
	void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &o, const PresidentialPardonForm &i);

#endif
