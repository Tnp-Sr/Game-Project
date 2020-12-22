#include "Bullet.h"

Bullet::Bullet(sf::Texture* texture, float pos_x, float pos_y, float x, float y, float movespeed)
{
	this->shap.setTexture(*texture);

	shap.setPosition(pos_x, pos_y);
	shap.setTextureRect(sf::IntRect(0, 0, 50, 100));
	this->direction.x = x;
	this->direction.y = y;
	this->moveSpeed = movespeed;
}

Bullet::~Bullet()
{
}

const sf::FloatRect Bullet::getBound() const
{
	return this->shap.getGlobalBounds();
}

const int& Bullet::getDamage() const
{
	return this->damage;
}

void Bullet::update()
{
	this->shap.move(this->moveSpeed * this->direction);
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->shap);
}
