#include "Entities.hpp"


float randf(float start = 0.0, float end = 1.0);


Entities::Entities()
{
}


void Entities::addEntities(std::queue<EntityInfo>& info)
{
	for (; !info.empty(); info.pop())
	{
		auto i = info.front();
		auto e = std::make_shared<Entity>();

		e->id = spawned+1;
		e->type = i.type;
		e->setPosition(i.pos);
		e->setTexture(i.texture);
		e->setOrigin(e->getTexture()->getSize().x / 2.0, e->getTexture()->getSize().y / 2.0);
		e->setRotation(i.rotation);

		switch (e->type)
		{
			case EntityType::Ship:
				e->health = 5;
				e->speed = 100;
				break;

			case EntityType::Bullet:
				e->speed = 300;
				e->damage = 1;
				break;

			case EntityType::Basic:
				e->health = 4;
				e->speed = 25;
				e->damage = 1;
				break;

			case EntityType::Shooter:
				e->health = 2;
				e->speed = 50;
				e->damage = 1;
				break;

			case EntityType::Asteroid:
				e->health = 1;
				e->damage = 1;
				e->speed = 50;
				e->setRotation(randf(0.0, 360.0));
				break;
		}

		entity_list.push_back(e);
		entity_map[e->type].push_back(e);

		spawned++;
	}
}


void Entities::removeEntities()
{
	for (int i = 0; i < entity_list.size(); i++)
	{
		if (entity_list[i]->expired)
		{
			entity_list.erase(entity_list.begin() + i);
		}
	}

	for (auto& [t, l] : entity_map)
	{
		for (int i = 0; i < l.size(); i++)
		{
			if (l[i]->expired)
			{
				l.erase(l.begin() + i);
			}
		}
	}
}

EntityMap& Entities::getEntityMap()
{
	return entity_map;
}


EntityList& Entities::getEntities()
{
	return entity_list;
}


EntityList& Entities::getEntitiesByType(EntityType type)
{
	return entity_map[type];
}


std::shared_ptr<Entity>& Entities::getShip()
{
	return entity_list[0];
}


const sf::Vector2f& Entities::getShipPosition()
{
	return entity_list[0]->getPosition();
}
