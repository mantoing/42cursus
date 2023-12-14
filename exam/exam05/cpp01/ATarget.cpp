#include "ATarget.hpp"

ATarget::ATarget()
{
}

ATarget::ATarget(const ATarget &src)
{
	_type = src.getType();
}

ATarget &ATarget::operator=(const ATarget &src)
{
	this->_type = src.getType();
	return (*this);
}

ATarget::~ATarget()
{
}

ATarget::ATarget(std::string type)
{
	_type = type;
}

const std::string &ATarget::getType() const
{
	return _type;
}

void ATarget::getHitBySpell(const ASpell &aspell) const
{
	std::cout << _type << " has been " << aspell.getEffects() << "!" << std::endl;
}
