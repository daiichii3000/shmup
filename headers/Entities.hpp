#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "Entity.hpp"

typedef std::vector<std::unique_ptr<Entity>> EntityList;

class Entities
{
private:
	EntityList entity_list;

public:
	size_t count = 0;

	Entities();
	void add(sf::Texture& texture);
	void remove();
	EntityList& getEntities();
};
