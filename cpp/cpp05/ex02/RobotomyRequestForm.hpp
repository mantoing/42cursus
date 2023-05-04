#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <stdlib.h>
# include <ctime>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm{
 private:
	std::string target;
 public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& obj);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);

	std::string getTarget() const;
	void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &o, const RobotomyRequestForm &i);

#endif
