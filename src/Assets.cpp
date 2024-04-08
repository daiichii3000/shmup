#include "Assets.hpp"

Assets::Assets()
{
	fonts["terminus"].loadFromFile("assets/terminus.ttf");

	textures["ship"].loadFromFile("assets/ship.png");
	textures["basic"].loadFromFile("assets/basic.png");
	textures["asteroid1"].loadFromFile("assets/asteroid1.png");
	textures["asteroid2"].loadFromFile("assets/asteroid2.png");
	textures["asteroid3"].loadFromFile("assets/asteroid3.png");
	textures["asteroid4"].loadFromFile("assets/asteroid4.png");
	textures["asteroid5"].loadFromFile("assets/asteroid5.png");
	textures["asteroid6"].loadFromFile("assets/asteroid6.png");
}

sf::Font& Assets::getFont(std::string name)
{
	return fonts[name];
}

sf::Texture& Assets::getTexture(std::string name)
{
	return textures[name];
}
