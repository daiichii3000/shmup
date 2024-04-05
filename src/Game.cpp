#include "Game.hpp"

#include <cmath>

float toDegree(float deg);
sf::Vector2f normalize(sf::Vector2f v);

Game::Game()
	: window(sf::VideoMode(1280, 720), "shmup", sf::Style::None, sf::ContextSettings(0,0,0)),
	  view(sf::FloatRect(0.0, 0.0, 640.0, 360.0))
{
	window.setFramerateLimit(60);
	window.setView(view);

	entities.add(EntityType::Ship, view.getCenter(), assets.getTexture("ship"));
	entities.add(EntityType::Basic, sf::Vector2f(100.0, 50.0), assets.getTexture("basic"));
	entities.add(EntityType::Basic, sf::Vector2f(140.0, 50.0), assets.getTexture("basic"));

	text.setFont(assets.getFont("terminus"));
	text.setCharacterSize(12);
	text.setPosition(view.getViewport().getPosition());
}

void Game::handleEvent()
{
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void Game::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		player.move_left = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		player.move_right = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		player.move_up = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		player.move_down = true;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		player.slowdown = true;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		player.fire = true;
}

void Game::movement()
{
	for (auto& en : entities.getEntities())
	{
		switch (en.type)
		{
			case EntityType::Ship:
			{
				sf::Vector2f ship_move;

				if (player.move_left)
					ship_move.x -= 1;
				if (player.move_right)
					ship_move.x += 1;
				if (player.move_up)
					ship_move.y -= 1;
				if (player.move_down)
					ship_move.y += 1;

				ship_move = normalize(ship_move);
				ship_move = ship_move * en.speed * dt;

				if (player.slowdown)
					ship_move = ship_move / (float)2.0;

				en.move(ship_move);

				/*
				sf::Vector2f ship_mouse;
				ship_mouse.x = en.getPosition().x - sf::Mouse::getPosition(window).x + window.getSize().x/2.0;
				ship_mouse.y = en.getPosition().y - sf::Mouse::getPosition(window).y + window.getSize().y/2.0;
				en.setRotation(toDegree(atan2f(ship_mouse.y, ship_mouse.x))-90);//en.getRotation()+30.0*dt);//
				text.setString
				(
					std::to_string(en.getPosition().x) + ", " + std::to_string(en.getPosition().y)
					+ "\n" +
					std::to_string(sf::Mouse::getPosition(window).x) + ", " + std::to_string(sf::Mouse::getPosition(window).y)
					+ "\n" +
					std::to_string(ship_mouse.x) + ", " + std::to_string(ship_mouse.y)
					+ "\n" + std::to_string(en.getRotation())
				);
				break;
				*/
			}

			case EntityType::Basic:
			{
				break;
			}
		}
	}
}

void Game::render()
{
	window.draw(text);
	for (auto& e : entities.getEntities())
	{
		window.draw(e);
	}
}

void Game::run()
{

	while (window.isOpen())
	{
		handleEvent();

		window.clear();

		dt = dt_clock.restart().asSeconds();

		player = PlayerAction();
		handleInput();

		movement();
		window.setView(view);

		render();

		window.display();
	}
}
