#include "SpellBook.hpp"

SpellBook::SpellBook()
{
}

SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *>::iterator it = _book.begin();
	while (it != _book.end())
	{
		delete it->second;
		it++;
	}
	_book.clear();
}

void SpellBook::learnSpell(ASpell *aspell)
{
	if (aspell)
		if (_book.find(aspell->getName()) == _book.end())
			_book[aspell->getName()] = aspell->clone();
}

void SpellBook::forgetSpell(std::string const &spell_name)
{
	if (_book.find(spell_name) != _book.end())
		delete _book[spell_name];
	_book.erase(spell_name);
}

ASpell *SpellBook::createSpell(std::string const &spell_name)
{
	if (_book.find(spell_name) != _book.end())
		return _book[spell_name];
	return NULL;
}
