#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>

class ATarget;
class ASpell
{
private:
	std::string _name;
	std::string _effects;

public:
	ASpell();
	ASpell(const ASpell &src);
	ASpell &operator=(const ASpell &src);
	virtual ~ASpell();

	ASpell(std::string name, std::string effects);
	const std::string &getName() const;
	const std::string &getEffects() const;

	virtual ASpell *clone() const = 0;

	void launch(const ATarget &atarget) const;
};

#include "ATarget.hpp"

#endif
