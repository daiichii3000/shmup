#pragma once

#include <SFML/Graphics/Font.hpp>

#include <map>
#include <string>
#include <iostream>

class Assets
{
private:
	std::map<std::string, sf::Font> fonts;
	std::map<std::string, sf::Texture> textures;

public:
	Assets();
	sf::Font& getFont(std::string);
	sf::Texture& getTexture(std::string);
};
