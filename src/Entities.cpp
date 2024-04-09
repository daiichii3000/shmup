#include "Entities.hpp"


float randf(float start = 0.0, float end = 1.0);


Entities::Entities()
{
}


void Entities::add(EntityType type, sf::Vector2f pos, sf::Texture& texture)
{
	auto e = std::make_shared<Entity>();
	e->id = spawned+1;
	e->type = type;
	e->setPosition(pos);
	e->setTexture(texture);
	e->setOrigin(texture.getSize().x / 2.0, texture.getSize().y / 2.0);

	switch (type)
	{
		case EntityType::Ship:
			e->health = 5;
			e->speed = 100;
			break;
		case EntityType::Basic:
			e->health = 4;
			e->speed = 25;
			break;
		case EntityType::Shooter:
			e->health = 2;
			e->speed = 50;
			break;
		case EntityType::Asteroid:
			e->speed = 50;
			e->setRotation(randf(0.0, 360.0));
			break;
	}

	entity_list.push_back(e);
	entity_map[type].push_back(e);

	spawned++;
}


void Entities::remove()
{
}

const EntityMap& Entities::getEntityMap()
{
	return entity_map;
}


const EntityList& Entities::getEntities()
{
	return entity_list;
}


const EntityList& Entities::getEntitiesByType(EntityType type)
{
	return entity_map[type];
}


const std::shared_ptr<Entity>& Entities::getShip()
{
	return entity_list[0];
}


const sf::Vector2f& Entities::getShipPosition()
{
	return entity_list[0]->getPosition();
}
