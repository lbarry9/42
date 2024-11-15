#include "ATarget.hpp"

ATarget::ATarget(std::string type) : type(type) {}

ATarget::~ATarget() {}

ATarget::ATarget(const ATarget &copy)
{
	*this = copy;
}

ATarget &ATarget::operator=(const ATarget &copy)
{
	this->type = copy.getType();
	return (*this);
}

std::string ATarget::getType() const
{
	return (type);
}

void ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << this->type << " has been " << spell.getEffects() << "!" << std::endl;
}
