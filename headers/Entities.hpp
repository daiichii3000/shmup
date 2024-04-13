#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <map>
#include <queue>

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
	void addEntities(std::queue<EntityInfo>& info);
	void removeEntities();
	EntityMap& getEntityMap();
	EntityList& getEntities();
	EntityList& getEntitiesByType(EntityType type);
	std::shared_ptr<Entity>& getShip();
	const sf::Vector2f& getShipPosition();
};
