#include "Game.hpp"

#include <cmath>
sf::Vector2f normalize(sf::Vector2f v);
float toDegree(float deg);
float toRadian(float deg);
float vector2len(const sf::Vector2f& A, const sf::Vector2f& B);
float twoPointsAngle(const sf::Vector2f& A, const sf::Vector2f& B);

void Game::movement()
{
	for (auto& en : entities.getEntities())
	{
		switch (en->type)
		{
			case Ship:
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

				if
				(
					en->getPosition().x + ship_move.x > view.getCenter().x + 290 ||
					en->getPosition().x + ship_move.x < view.getCenter().x - 290 ||
					en->getPosition().y + ship_move.y > view.getCenter().y + 150 ||
					en->getPosition().y + ship_move.y < view.getCenter().y - 150
				)
					view.move(ship_move);

				if (player.slowdown)
					ship_move = ship_move / (float)2.0;

				en->move(ship_move);

				sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
				en->setRotation(twoPointsAngle(mouse, en->getPosition())+90);
				break;
			}

			case Bullet:
			{
				en->move
				(
					std::cos(toRadian(en->getRotation()-90)) * en->speed * dt,
					std::sin(toRadian(en->getRotation()-90)) * en->speed * dt
				);
				break;
			}

			case Basic:
			{
				en->rotate(45.0*dt);
				en->move(normalize(entities.getShipPosition() - en->getPosition()) * en->speed * dt);
				break;
			}

			case Shooter:
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

			case Asteroid:
			{
				en->rotate(15.0*dt);
				break;
			}
		}
	}
}


