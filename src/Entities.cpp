#include "Entities.hpp"

Entities::Entities()
{
}

void Entities::add(EntityType type, sf::Vector2f pos, sf::Texture& texture)
{
	Entity e;
	e.id = count+1;
	e.type = type;
	e.setPosition(pos);
	e.setTexture(texture);
	e.setOrigin(texture.getSize().x / 2.0, texture.getSize().y / 2.0);
	switch (type)
	{
		case EntityType::Ship:
			e.health = 5;
			e.speed = 100;
			break;
		case EntityType::Basic:
			e.health = 3;
			e.speed = 5;
			break;
	}

	entity_list.push_back(e);

	count++;
}

void Entities::remove()
{
}

EntityList& Entities::getEntities()
{
	return entity_list;
}
