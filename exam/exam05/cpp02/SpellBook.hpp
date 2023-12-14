#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include "ASpell.hpp"
#include <map>

class SpellBook
{
private:
	std::map<std::string, ASpell *> _book;

	SpellBook(const SpellBook &src);
	SpellBook &operator=(const SpellBook &src);

public:
	SpellBook();
	virtual ~SpellBook();

	void learnSpell(ASpell *aspell);
	void forgetSpell(std::string const &spell_name);
	ASpell *createSpell(std::string const &spell_name);
};

#endif