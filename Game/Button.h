#pragma once
#pragma once

#include<stdio.h>
#include<iostream>

#include<ctime>
#include<cstdlib>
#include<sstream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>

enum button_state { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };

class Button
{

private:

	short unsigned buttonState;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color text_idle;
	sf::Color text_hover;
	sf::Color text_active;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;



public:
	Button(float x, float y, float w, float h,
		sf::Font* font, std::string text, unsigned Character_size,
		sf::Color text_idle, sf::Color text_hover, sf::Color text_active,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	~Button();

	//Accessors
	const bool isPressed() const;

	//Function

	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget& target);
};


