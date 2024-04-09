#pragma once

#include <SFML/Graphics.hpp>

enum EntityType
{
	Ship,
	//Bullet,
	Basic,
	Shooter,
	Asteroid
};

class Entity : public sf::Sprite
{
private:
public:
	EntityType type;
	size_t id = 0;
	float health = 0;
	float speed = 0;
	float damage = 0;

	Entity();
};
