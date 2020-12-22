#ifndef BULLET_H
#define BULLET_H

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<stdio.h>

class Bullet
{
private:


	sf::Sprite shap;

	sf::Vector2f direction;
	float moveSpeed;
	int damage = 50;

public:
	Bullet(sf::Texture* texture, float pos_x, float pos_y, float x, float y, float moveSpeed);
	virtual ~Bullet();

	const sf::FloatRect getBound() const;
	const  int& getDamage() const;

	void update();
	void render(sf::RenderTarget* target);
};

#endif // !BULLET_H

