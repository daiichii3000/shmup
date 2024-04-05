#include <random>
#include <cmath>
#include <SFML/System.hpp>

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
