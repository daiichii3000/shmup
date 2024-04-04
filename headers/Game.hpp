#pragma once

#include <SFML/Graphics.hpp>
#include "Assets.hpp"
#include "Entities.hpp"

class Game
{
private:
	sf::RenderWindow window;
	sf::View view;
	sf::Event ev;
	sf::Text text;
	Assets assets;
	Entities entities;

public:
	Game();
	void render();
	void run();
};
