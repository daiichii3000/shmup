#pragma once

#include <SFML/Graphics.hpp>

enum EntityType
{
	Ship,
	Bullet,
	Basic,
	Shooter,
	Asteroid
};

struct EntityInfo
{
	EntityType type;
	sf::Vector2f pos;
	sf::Texture& texture;
	float rotation;
};

class Entity : public sf::Sprite
{
private:
public:
	EntityType type;
	size_t id = 0;
	float speed = 0;
	int health = 0;
	int damage = 0;
	bool expired = false;
	sf::Clock invul_clock;

	Entity();
};
