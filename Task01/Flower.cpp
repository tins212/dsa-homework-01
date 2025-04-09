#include "Flower.h"

Flower::Flower(sf::RenderWindow& window)
{
	this->window = &window;

	outer_flower.setRadius(100.f);
	outer_flower.setPosition(sf::Vector2f(400.f, 400.f));
	outer_flower.setOrigin(sf::Vector2f(100.f, 100.f));
	outer_flower.setFillColor(sf::Color::Red);

	inner_flower.setRadius(50.f);
	inner_flower.setPosition(sf::Vector2f(400.f, 400.f));
	inner_flower.setOrigin(sf::Vector2f(50.f, 50.f));
	inner_flower.setFillColor(sf::Color::Yellow);

	stem.setSize({ 400.f,15.f });
	stem.setFillColor(sf::Color::Green);
	stem.setPosition(sf::Vector2f(400.f, 400.f));
	stem.setRotation(sf::degrees(90.f));

	time_limit = sf::seconds(2.f);
	is_rotated = false;
}

void Flower::draw()
{
	if (clock.getElapsedTime() >= time_limit) {

		if (!is_rotated) {
			outer_flower.rotate(sf::degrees(45));
			inner_flower.rotate(sf::degrees(45));
			stem.rotate(sf::degrees(45));
			is_rotated = true;
		}
		else {
			outer_flower.rotate(sf::degrees(-90));
			inner_flower.rotate(sf::degrees(-90));
			stem.rotate(sf::degrees(-90));
			is_rotated = false;
		}

		clock.restart();
	}

	window->draw(stem);
	window->draw(outer_flower);
	window->draw(inner_flower);
}
