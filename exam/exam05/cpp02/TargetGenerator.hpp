#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
private:
	TargetGenerator(const TargetGenerator &src);
	TargetGenerator &operator=(const TargetGenerator &src);

	std::map<std::string, ATarget *> _book;

public:
	TargetGenerator();
	virtual ~TargetGenerator();

	void learnTargetType(ATarget *atarget);
	void forgetTargetType(std::string const &type);
	ATarget *createTarget(std::string const &type);
};

#endif