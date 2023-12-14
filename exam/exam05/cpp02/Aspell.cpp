#include "ASpell.hpp"

ASpell::ASpell()
{
}

ASpell::ASpell(const ASpell &src)
{
	_name = src.getName();
	_effects = src.getEffects();
}

ASpell &ASpell::operator=(const ASpell &src)
{
	this->_name = src.getName();
	this->_effects = src.getEffects();
	return (*this);
}

ASpell::~ASpell()
{
}

ASpell::ASpell(std::string name, std::string effects)
{
	_name = name;
	_effects = effects;
}

const std::string &ASpell::getName() const
{
	return _name;
}

const std::string &ASpell::getEffects() const
{
	return _effects;
}

void ASpell::launch(const ATarget &atarget) const
{
	atarget.getHitBySpell(*this);
}