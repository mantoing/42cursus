# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("rrf", 72, 45), target("") {

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("rrf", 72, 45), target(target) {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj) {
	*this = obj;
}

RobotomyRequestForm::~RobotomyRequestForm() {

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
	target = obj.getTarget();
	return (*this);
} 

std::string RobotomyRequestForm::getTarget() const {
	return (target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!(this->getSign_check())){
		throw RobotomyRequestForm::CheckSigned();
	}
	else if (executor.getGrade() > this->getGrade_exe()){
		throw RobotomyRequestForm::ExecuteFailedException();
	}
	srand(time(NULL));
	std::cout << "driiiiiiiiiiiiiiilllll\n" << std::endl;
	if (rand() % 2 == 1)
		std::cout << target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << target << " has been robotomized failed..." << std::endl;
}

std::ostream &operator<<(std::ostream &o, const RobotomyRequestForm &i) {
	o << "name : " << i.getName() << std::endl << "Grade to sign : " << i.getGrade_sign()
	<< std::endl << "Grade to execute : " << i.getGrade_exe() << std::endl;
	return o;
}