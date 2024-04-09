#pragma once

#include <SFML/Graphics.hpp>
#include "Assets.hpp"
#include "Entities.hpp"
#include "Timers.hpp"

struct PlayerAction
{
	bool move_up = false;
	bool move_down = false;
	bool move_left = false;
	bool move_right = false;
	bool slowdown = false;
	bool fire = false;
};

class Game
{
private:
	sf::RenderWindow window;
	sf::View view;
	sf::Event event;
	sf::Text text; //debug
	sf::CircleShape point;// debug

	Assets assets;
	Entities entities;
	Timers timers;

	PlayerAction player;

	float dt;
	sf::Clock dt_clock;

public:
	Game();
	void handleEvent();
	void handleInput();
	void movement();
	void render();
	void spawnEnemies();
	void run();
};
