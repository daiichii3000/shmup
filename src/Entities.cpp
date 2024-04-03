#include "Entities.hpp"

Entities::Entities()
{
}

void Entities::add()
{
	entity_list.push_back(std::make_unique<Entity>(sf::Vector2f(50,50)));
	count++;
}

void Entities::remove()
{
}

EntityList& Entities::getEntities()
{
	return entity_list;
}
