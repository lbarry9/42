#pragma once

#include <string>
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected:
		std::string name;
		std::string effects;

	public:
		virtual ~ASpell();
		ASpell(std::string name, std::string effects);
		ASpell(const ASpell &copy);
		ASpell &operator=(const ASpell &copy);
		std::string getName() const;
		std::string getEffects() const;
		virtual ASpell* clone() const = 0;
		void launch(const ATarget &target) const;
};
