#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("scf", 145, 137), target("") {

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("scf", 145, 137), target(target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj) {
	*this = obj;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
	target = obj.getTarget();
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const {
	return (target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	std::ofstream ofs;
	std::string ascii_tree =
	"    *\n"
	"   ***\n"
	"  *****\n"
	" *******\n"
	"   | |\n";

	if(!(this->getSign_check())){
		throw ShrubberyCreationForm::CheckSigned();
	}
	else if(executor.getGrade() > this->getGrade_exe()){
		throw ShrubberyCreationForm::ExecuteFailedException();
	}
	ofs.open(target + "_shrubbery");
	if (ofs.is_open() == true) {
		ofs << ascii_tree;
	} else {
		throw ShrubberyCreationForm::FailOpenFile();
	}
	ofs.close();
}

const char* ShrubberyCreationForm::FailOpenFile::what() const throw() {
	return ("Failed open File");
}

std::ostream &operator<<(std::ostream &o, const ShrubberyCreationForm &i) {
	o << "name : " << i.getName() << std::endl << "Grade to sign : " << i.getGrade_sign()
	<< std::endl << "Grade to execute : " << i.getGrade_exe() << std::endl;
	return o;
}