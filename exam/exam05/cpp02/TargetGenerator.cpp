#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
}

TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget *>::iterator it = _book.begin();
	while (it != _book.end())
	{
		delete it->second;
		it++;
	}
	_book.clear();
}

void TargetGenerator::learnTargetType(ATarget *atarget)
{
	if (atarget)
		if (_book.find(atarget->getType()) == _book.end())
			_book[atarget->getType()] = atarget->clone();
}

void TargetGenerator::forgetTargetType(std::string const &type)
{
	if (_book.find(type) != _book.end())
		delete _book[type];
	_book.erase(type);
}

ATarget *TargetGenerator::createTarget(std::string const &type)
{
	if (_book.find(type) != _book.end())
		return _book[type];
	return NULL;
}
