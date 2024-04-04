#include "Entities.hpp"

Entities::Entities()
{
}

void Entities::add(sf::Texture& texture)
{
	entity_list.push_back(std::make_unique<Entity>(sf::Vector2f(50,50), texture));
	count++;
}

void Entities::remove()
{
}

EntityList& Entities::getEntities()
{
	return entity_list;
}
