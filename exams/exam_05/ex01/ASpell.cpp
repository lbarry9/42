#include "ASpell.hpp"

ASpell::ASpell(std::string name, std::string effects) : name(name), effects(effects) {}

ASpell::~ASpell() {}

ASpell::ASpell(const ASpell &copy)
{
	*this = copy;
}

ASpell &ASpell::operator=(const ASpell &copy)
{
	this->name = copy.getName();
	this->effects = copy.getEffects();
	return (*this);
}

std::string ASpell::getName() const
{
	return (name);
}

std::string ASpell::getEffects() const
{
	return (effects);
}

void ASpell::launch(const ATarget &target) const
{
	target.getHitBySpell(*this);
}
