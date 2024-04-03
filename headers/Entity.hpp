#pragma once

#include <SFML/Graphics.hpp>

class Entity : public sf::Sprite
{
private:
public:
	Entity(sf::Vector2f);
	Entity(sf::Vector2f, const sf::Texture&);
};
