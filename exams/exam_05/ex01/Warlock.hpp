#pragma once
#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"

class Warlock
{
	private:
		std::string name;
		std::string title;
		Warlock();
		Warlock(Warlock const &copy);
		Warlock &operator=(Warlock const &copy);
		std::map<std::string, ASpell*> spellBook;

	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();
		std::string const &getName() const;
		std::string const &getTitle() const;
		void setTitle(std::string const &title);
		void introduce() const;
		void learnSpell(ASpell* spell);
		void forgetSpell(std::string spellName);
		void launchSpell(std::string spellName, ATarget &target);
};
