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
	spellBook.learnSpell(spell);
}

void Warlock::forgetSpell(std::string spellName)
{
	spellBook.forgetSpell(spellName);
}

void Warlock::launchSpell(std::string spellName, ATarget const &target)
{
	if (spellBook.createSPell(spellName))
		spellBook.createSPell(spellName)->launch(target);
}
