#pragma once
#include <SFML/Graphics.hpp>

class Flower {
public:
	Flower(sf::RenderWindow& window);
	void draw();
private:
	sf::RenderWindow* window;
	sf::RectangleShape stem;
	sf::CircleShape inner_flower;
	sf::CircleShape outer_flower;

	sf::Time time_limit;
	sf::Clock clock;
	bool is_rotated;
};