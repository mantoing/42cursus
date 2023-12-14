#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
private:
	std::string _name;
	std::string _title;

	Warlock();
	Warlock(const Warlock &src);
	Warlock &operator=(const Warlock &src);

	SpellBook _book;

public:
	~Warlock();

	Warlock(std::string name, std::string title);
	const std::string &getName() const;
	const std::string &getTitle() const;

	void setTitle(const std::string &title);
	void introduce() const;

	void learnSpell(ASpell *aspell);
	void forgetSpell(std::string name);
	void launchSpell(std::string name, const ATarget &atarget);
};

#endif
