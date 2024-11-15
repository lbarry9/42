#include "SpellBook.hpp"

SpellBook::SpellBook(SpellBook const &copy)
{
	*this = copy;
}

SpellBook &SpellBook::operator=(SpellBook const &copy)
{
	spellBook = copy.spellBook;
	return (*this);
}

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
	for (std::map<std::string, ASpell*>::iterator it = spellBook.begin(); it != spellBook.end(); it++)
		delete it->second;
	spellBook.clear();
}

void SpellBook::learnSpell(ASpell* spell)
{
	if (spell)
	{
		spellBook[spell->getName()] = spell->clone();
	}
}

void SpellBook::forgetSpell(std::string const &spellName)
{
	std::map<std::string, ASpell*>::iterator it = spellBook.find(spellName);
	if (it != spellBook.end())
	{
		delete it->second;
		spellBook.erase(it);
	}
}

ASpell* SpellBook::createSPell(std::string const &spellName)
{
	ASpell* tmp = NULL;
	if (spellBook.find(spellName) != spellBook.end())
		tmp = spellBook[spellName];
	return(tmp);
}
