#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <map>

#include "Entity.hpp"

typedef std::vector<std::shared_ptr<Entity>> EntityList;
typedef std::map<EntityType, EntityList> EntityMap;

class Entities
{
private:
	EntityList entity_list;
	EntityMap entity_map;

public:
	size_t spawned = 0;

	Entities();
	void add(EntityType, sf::Vector2f, sf::Texture&);
	void remove();
	const EntityMap& getEntityMap();
	const EntityList& getEntities();
	const EntityList& getEntitiesByType(EntityType type);
	const std::shared_ptr<Entity>& getShip();
	const sf::Vector2f& getShipPosition();
};
