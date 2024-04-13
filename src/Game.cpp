#include "Game.hpp"


float randf(float start = 0.0, float end = 1.0);


Game::Game()
	: window(sf::VideoMode(1920, 1080), "shmup", sf::Style::None, sf::ContextSettings(0,0,0)),
	  view(sf::FloatRect(0.0, 0.0, 640.0, 360.0))
{
	window.setFramerateLimit(60);
	window.setView(view);

	cursor.loadFromPixels(shooter_cursor.pixel_data, sf::Vector2u(shooter_cursor.width, shooter_cursor.width), sf::Vector2u(16,16));
	window.setMouseCursor(cursor);

	entities_to_add.push(EntityInfo{Ship, view.getCenter(), assets.getTexture("ship")});

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
	{
		player.fire = true;
	}
}


void Game::action()
{
	if (player.fire)
	{
		if (timers.firing_timer.getElapsedTime() >= timers.firing_cooldown)
		{
			entities_to_add.push(EntityInfo
			{
				Bullet,
				entities.getShipPosition(),
				assets.getTexture("bullet"),
				entities.getShip()->getRotation()
			});
			timers.firing_timer.restart();
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
	entities_to_add.push(EntityInfo
	{
		Basic,
		sf::Vector2f(100.0, 50),
		assets.getTexture("basic")
	});

	entities_to_add.push(EntityInfo
	{
		Shooter,
		sf::Vector2f(140.0, 50),
		assets.getTexture("shooter")
	});
	entities_to_add.push(EntityInfo
	{
		Asteroid,
		sf::Vector2f(randf(40.0,500.0), randf(20,340.0)),
		assets.getTexture("asteroid" + std::to_string((int)randf(1.0,6.99)))
	});
}


void Game::run()
{
	spawnEnemies();

	while (window.isOpen())
	{
		window.clear();
		text.setString("");

		player = PlayerAction();
		dt = timers.dt_clock.restart().asSeconds();

		if (!entities_to_add.empty())
			entities.addEntities(entities_to_add);

		handleEvent();
		handleInput();
		action();
		movement();
		window.setView(view);
		collision();

		text.setString(std::to_string(entities.getShip()->health));
		//text.setString(std::to_string(timers.game_time.getElapsedTime().asSeconds()));
		render();

		entities.removeEntities();

		window.display();
	}
}
