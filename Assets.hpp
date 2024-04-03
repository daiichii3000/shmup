#pragma once

#include <map>
#include <string>

class Assets
{
private:
	std::map<std::string, sf::Font> fonts;

public:
	Assets();
	sf::Font& getFont(std::string);
};
