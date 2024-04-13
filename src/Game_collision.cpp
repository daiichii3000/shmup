#include "Game.hpp"

void Game::collision()
{
	auto& ship = entities.getShip();
	for (auto& en : entities.getEntities())
	{
		if
		(
			en->type == Basic ||
			en->type == Shooter ||
			en->type == Asteroid
		)
		{
			if (en->getGlobalBounds().intersects(ship->getGlobalBounds()))
			{
				if (ship->invul_clock.getElapsedTime() >= timers.invul_time)
				{
					en->health -= 1;
					ship->health -= en->damage;
					ship->invul_clock.restart();
				}
				if (ship->health <= 0)
					ship->expired = true;
			}

			for (auto& b : entities.getEntitiesByType(Bullet))
			{
				if (en->getGlobalBounds().intersects(b->getGlobalBounds()))
				{
					en->health -= b->damage;
					b->expired = true;
				}
				if (en->health <= 0)
					en->expired = true;
			}
		}

		if (en->type == Bullet)
		{
			if (en->invul_clock.getElapsedTime() > timers.bullet_lifetime)
				en->expired = true;
		}
	}
}
