#include <random>
#include <cmath>
#include <SFML/Graphics/Sprite.hpp>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<float> dist;

// Generate float from 0 to 1
float randf(float start = 0.0, float end = 1.0)
{
	return (dist(gen) * end) + start;
}

float toRadian(float deg)
{
	return deg*M_PI/180.0;
}

float toDegree(float rad)
{
	return rad*180.0/M_PI;
}

sf::Vector2f normalize(sf::Vector2f v)
{
	float len = std::sqrt(v.x*v.x + v.y*v.y);
	if (len == 1.0 || len == 0.0)
		return v;
	v.x /= len;
	v.y /= len;
	return v;
}

float vector2len(const sf::Vector2f& A, const sf::Vector2f& B)
{
	sf::Vector2f L;
	L = A - B;

	return sqrt(L.x*L.x + L.y*L.y);
}

float twoPointsAngle(const sf::Vector2f& A, const sf::Vector2f& B)
{
	sf::Vector2f diff;
	diff = A - B;
	return toDegree(atan2(diff.y, diff.x));
}

/*
bool circleTest(const sf::Sprite& sprite1, const sf::Sprite& sprite2)
{
	auto spr1Size = getSpriteSize(sprite1);
	auto spr2Size = getSpriteSize(sprite2);
	auto radius1 = (spr1Size.x + spr1Size.y) / 4.f;
	auto radius2 = (spr2Size.x + spr2Size.y) / 4.f;

	auto diff = getSpriteCenter(sprite1) - getSpriteCenter(sprite2);

	return (diff.x * diff.x + diff.y * diff.y <= (radius1 + radius2) * (radius1 + radius2));
}
*/
