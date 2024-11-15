#include "Warlock.hpp"

// private
Warlock::Warlock() {}

Warlock &Warlock::operator=(const Warlock &copy)
{
	this->name = copy.name;
	this->title = copy.title;
	return (*this);
}

Warlock::Warlock(const Warlock &copy)
{
	*this = copy;
}

//public
Warlock::Warlock(const std::string &name, const std::string &title) : name(name), title(title)
{
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!" << std::endl;
	for (std::map<std::string, ASpell*>::iterator it = spellBook.begin(); it != spellBook.end(); it++)
		delete it->second;
	spellBook.clear();
}

std::string const &Warlock::getName() const
{
	return (name);
}

std::string const &Warlock::getTitle() const
{
	return (title);
}

void Warlock::setTitle(std::string const &str)
{
	title = str;
}

void Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}


void Warlock::learnSpell(ASpell* spell)
{
	if (spell)
	{
		if (spellBook.find(spell->getName()) == spellBook.end())
			spellBook[spell->getName()] = spell->clone();
	}
}

void Warlock::forgetSpell(std::string spellName)
{
	if (spellBook.find(spellName) != spellBook.end())
	{
		delete spellBook[spellName];
		spellBook.erase(spellBook.find(spellName));
	}
}

void Warlock::launchSpell(std::string spellName, ATarget &target)
{
	if (spellBook.find(spellName) != spellBook.end())
	{
		spellBook[spellName]->launch(target);
	}
}
