#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
private:
public:
	Fwoosh();
	~Fwoosh();

	virtual ASpell *clone() const;
};

#endif
