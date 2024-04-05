#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "Entity.hpp"

typedef std::vector<Entity> EntityList;

class Entities
{
private:
	EntityList entity_list;

public:
	size_t count = 0;

	Entities();
	void add(EntityType, sf::Vector2f, sf::Texture&);
	void remove();
	EntityList& getEntities();
};
