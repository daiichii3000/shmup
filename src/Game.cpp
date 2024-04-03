#include "Game.hpp"

Game::Game()
	: window(sf::VideoMode(1280, 720), "shmup", sf::Style::None, sf::ContextSettings(0,0,16))
{
	window.setFramerateLimit(60);

	entities.add();
}

void Game::run()
{

	while (window.isOpen())
	{
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		for (auto& e : entities.getEntities())
		{
			window.draw(*e);
		}

		window.display();
	}
}
