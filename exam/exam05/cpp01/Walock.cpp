#include "Warlock.hpp"

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
	std::map<std::string, ASpell *>::iterator it = book.begin();
	while (it != book.end())
	{
		delete it->second;
		it++;
	}
	book.clear();
}

Warlock::Warlock(std::string name, std::string title)
{
	_name = name;
	_title = title;
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

const std::string &Warlock::getName() const
{
	return _name;
}

const std::string &Warlock::getTitle() const
{
	return _title;
}

void Warlock::setTitle(const std::string &title)
{
	_title = title;
}

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *aspell)
{
	if (aspell)
	{
		if (book.find(aspell->getName()) == book.end())
		{
			book[aspell->getName()] = aspell->clone();
		}
	}
}

void Warlock::forgetSpell(std::string name)
{
	std::map<std::string, ASpell *>::iterator i = book.find(name);
	if (i != book.end())
	{
		delete i->second;
	}
	book.erase(name);
}

void Warlock::launchSpell(std::string name, const ATarget &atarget)
{
	// std::map<std::string, ASpell *>::iterator i = book.find(name);
	// if (i != book.end())
	// 	i->second->launch(atarget);
	ASpell *as = book[name];
	if (as)
		as->launch(atarget);
}
