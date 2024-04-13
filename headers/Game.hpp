#pragma once

#include <SFML/Graphics.hpp>

#include "Assets.hpp"
#include "Entities.hpp"

struct PlayerAction
{
	bool move_up = false;
	bool move_down = false;
	bool move_left = false;
	bool move_right = false;
	bool slowdown = false;
	bool fire = false;
};

struct Timers
{
	sf::Clock dt_clock;
	sf::Clock game_time;
	sf::Clock firing_timer;
	sf::Time firing_cooldown = sf::milliseconds(200);
	sf::Time invul_time = sf::seconds(1);
	sf::Time bullet_lifetime = sf::seconds(5);
};

class Game
{
private:
	sf::RenderWindow window;
	sf::View view;
	sf::Event event;
	sf::Cursor cursor;
	sf::Text text; //debug
	sf::CircleShape point;// debug

	std::queue<EntityInfo> entities_to_add;

	Assets assets;
	Entities entities;
	Timers timers;

	PlayerAction player;

	float dt;

public:
	Game();
	void handleEvent();
	void handleInput();
	void action();
	void movement();
	void collision();
	void render();
	void spawnEnemies();
	void run();
};
