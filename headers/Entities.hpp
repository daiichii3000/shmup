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
	size_t count = 0;

	Entities();
	void add(EntityType, sf::Vector2f, sf::Texture&);
	void remove();
	EntityMap& getEntityMap();
	EntityList& getEntities();
	EntityList& getEntitiesByType(EntityType type);
	std::shared_ptr<Entity>& getShip();
};
