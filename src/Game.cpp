#include "Game.hpp"

Game::Game()
	: window(sf::VideoMode(1280, 720), "shmup", sf::Style::None, sf::ContextSettings(0,0,16)),
	  view(sf::FloatRect(0.0, 0.0, 640.0, 360.0))
{
	window.setFramerateLimit(60);
	window.setView(view);

	entities.add(assets.getTexture("ship"));
}

void Game::render()
{
	for (auto& e : entities.getEntities())
	{
		window.draw(*e);
	}
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

		render();

		window.display();
	}
}
