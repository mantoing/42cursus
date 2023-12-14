#ifndef Dummy_HPP
#define Dummy_HPP

#include "ATarget.hpp"

class Dummy : public ATarget
{
public:
	Dummy();
	~Dummy();

	ATarget *clone() const;
};

#endif
