#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>

class ASpell;
class ATarget
{
private:
	std::string _type;

public:
	ATarget();
	ATarget(const ATarget &src);
	ATarget &operator=(const ATarget &src);
	virtual ~ATarget();

	ATarget(std::string type);
	const std::string &getType() const;

	void getHitBySpell(const ASpell &aspell) const;

	virtual ATarget *clone() const = 0;
};

#include "ASpell.hpp"

#endif
