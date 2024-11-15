#pragma once

#include "ASpell.hpp"
#include <map>

class SpellBook
{
	private:
		SpellBook(SpellBook const &copy);
		SpellBook &operator=(SpellBook const &copy);
		std::map<std::string, ASpell*> spellBook;

	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell* spell);
		void forgetSpell(std::string const &spellName);
		ASpell* createSPell(std::string const &spellName);
};
