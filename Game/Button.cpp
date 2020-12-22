#include "Button.h"

Button::Button(float x, float y, float w, float h,
	sf::Font* font, std::string text, unsigned Character_size,
	sf::Color text_idle, sf::Color text_hover, sf::Color text_active,
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{

	this->buttonState = BTN_IDLE;

	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(w, h));
	this->shape.setFillColor(idleColor);

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(text_idle);
	this->text.setCharacterSize(Character_size);
	this->text.setPosition(this->shape.getPosition().x + (w / 4), this->shape.getPosition().y + (h / 4));

	this->text_idle = text_idle;
	this->text_hover = text_hover;
	this->text_active = text_active;

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;
}

Button::~Button()
{
}

//Accessors

const bool Button::isPressed() const
{
	if (this->buttonState == BTN_ACTIVE)
	{
		return true;
	}
	else
	{
		return false;
	}

}

//Function

void Button::update(const sf::Vector2f mousePos)
{
	//update bool for hover and pressed

	// = 0
	this->buttonState = BTN_IDLE;

	//hover
	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = BTN_HOVER;

		//pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = BTN_ACTIVE;
		}
	}

	switch (this->buttonState)
	{
	case BTN_IDLE:
		this->shape.setFillColor(this->idleColor);
		this->text.setFillColor(this->text_idle);
		break;

	case BTN_HOVER:
		this->shape.setFillColor(this->hoverColor);
		this->text.setFillColor(this->text_hover);
		break;

	case BTN_ACTIVE:
		this->shape.setFillColor(this->activeColor);
		this->text.setFillColor(this->text_active);
		break;

	default:
		this->shape.setFillColor(sf::Color::Red);
		this->text.setFillColor(sf::Color::Blue);
		break;

	}
}

void Button::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
	target.draw(this->text);
}

