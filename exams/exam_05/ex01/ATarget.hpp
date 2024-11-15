#pragma once
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	protected:
		std::string type;

	public:
		ATarget(std::string type);
		virtual ~ATarget();
		ATarget(const ATarget &copy);
		ATarget &operator=(const ATarget &copy);
		std::string getType() const;
		virtual ATarget* clone() const = 0;
		void getHitBySpell(const ASpell &spell) const;
};
