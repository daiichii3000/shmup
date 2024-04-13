#pragma once

#include <SFML/Graphics/Font.hpp>

#include <map>
#include <string>
#include <iostream>

#include "../assets/cursor.h"

typedef std::map<std::string, sf::Font> FontMap;
typedef std::map<std::string, sf::Texture> TextureMap;

class Assets
{
private:
	FontMap fonts;
	TextureMap textures;

public:
	Assets();
	sf::Font& getFont(std::string);
	sf::Texture& getTexture(std::string);
	TextureMap& getTextureMap();
};
