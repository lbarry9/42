#pragma once
#include <iostream>
#include <string>

class Warlock
{
	private:
		std::string name;
		std::string title;
		Warlock();
		Warlock(Warlock const &copy);
		Warlock &operator=(Warlock const &copy);


	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();
		std::string const &getName() const;
		std::string const &getTitle() const;
		void setTitle(std::string const &title);
		void introduce() const;
};
