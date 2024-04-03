#include "Entity.hpp"

Entity::Entity(sf::Vector2f pos)
{
	setPosition(pos);
}

Entity::Entity(sf::Vector2f pos, const sf::Texture& texture)
	: Sprite(texture)
{
	setPosition(pos);
}
