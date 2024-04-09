#include "Game.hpp"


float randf(float start = 0.0, float end = 1.0);
float toDegree(float deg);
sf::Vector2f normalize(sf::Vector2f v);
float vector2len(const sf::Vector2f& A, const sf::Vector2f& B);
float twoPointsAngle(const sf::Vector2f& A, const sf::Vector2f& B);


Game::Game()
	: window(sf::VideoMode(1280, 720), "shmup", sf::Style::None, sf::ContextSettings(0,0,0)),
	  view(sf::FloatRect(0.0, 0.0, 640.0, 360.0))
{
	window.setFramerateLimit(60);
	window.setView(view);

	entities.add(EntityType::Ship, view.getCenter(), assets.getTexture("ship"));

	text.setFont(assets.getFont("terminus"));
	text.setCharacterSize(12);
	text.setPosition(view.getViewport().getPosition());

	point.setRadius(5.0);
	point.setOrigin(5.0,5.0);
}


void Game::handleEvent()
{
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		/*
		if (event.type == sf::Event::MouseWheelScrolled)
		{
			if (event.mouseWheelScroll.delta < 0)
				view.zoom(0.8);
			else
				view.zoom(1.2);
		}
		*/
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
		switch (en->type)
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
				ship_move = ship_move * en->speed * dt;

				if (player.slowdown)
					ship_move = ship_move / (float)2.0;

				en->move(ship_move);

				sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
				en->setRotation(twoPointsAngle(mouse, en->getPosition())+90);
				break;
			}

			case EntityType::Basic:
			{
				en->rotate(45.0*dt);
				en->move(normalize(entities.getShipPosition() - en->getPosition()) * en->speed * dt);
				break;
			}

			case EntityType::Shooter:
			{
				en->setRotation(twoPointsAngle(entities.getShipPosition(), en->getPosition())-90);

				float dist = vector2len(en->getPosition(), entities.getShip()->getPosition());
				sf::Vector2f norm = normalize(entities.getShip()->getPosition() - en->getPosition()) * en->speed * dt;
				sf::Vector2f movement;
				movement.x = norm.y;
				movement.y = -norm.x;

				if (dist > 80)
					en->move(norm);
				else
					en->move(movement);
				break;
			}

			case EntityType::Asteroid:
			{
				en->rotate(15.0*dt);
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
		window.draw(*e);
	}
}


void Game::spawnEnemies()
{
	entities.add(EntityType::Basic, sf::Vector2f(100.0, 50.0), assets.getTexture("basic"));
	entities.add(EntityType::Basic, sf::Vector2f(140.0, 50.0), assets.getTexture("basic"));

	entities.add(EntityType::Shooter, sf::Vector2f(180.0, 100.0), assets.getTexture("shooter"));

	entities.add(EntityType::Asteroid, sf::Vector2f(randf(40.0,600.0), randf(20,340.0)), assets.getTexture("asteroid" + std::to_string((int)randf(1.0,6.99))));
	entities.add(EntityType::Asteroid, sf::Vector2f(randf(40.0,600.0), randf(20,340.0)), assets.getTexture("asteroid" + std::to_string((int)randf(1.0,6.99))));
	entities.add(EntityType::Asteroid, sf::Vector2f(randf(40.0,600.0), randf(20,340.0)), assets.getTexture("asteroid" + std::to_string((int)randf(1.0,6.99))));
	entities.add(EntityType::Asteroid, sf::Vector2f(randf(40.0,600.0), randf(20,340.0)), assets.getTexture("asteroid" + std::to_string((int)randf(1.0,6.99))));
	entities.add(EntityType::Asteroid, sf::Vector2f(randf(40.0,600.0), randf(20,340.0)), assets.getTexture("asteroid" + std::to_string((int)randf(1.0,6.99))));
}


void Game::run()
{
	spawnEnemies();

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
