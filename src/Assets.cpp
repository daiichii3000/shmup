#include "Assets.hpp"

Assets::Assets()
{
	fonts["terminus"].loadFromFile("assets/terminus.ttf");

	textures["ship"].loadFromFile("assets/ship.png");
	textures["basic"].loadFromFile("assets/basic.png");
}

sf::Font& Assets::getFont(std::string name)
{
	return fonts[name];
}

sf::Texture& Assets::getTexture(std::string name)
{
	return textures[name];
}
