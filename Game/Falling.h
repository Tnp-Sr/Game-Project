#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include"SFML/Graphics.hpp"

class Falling
{
private:
	unsigned pointCount;

	int e_SizeX;
	int e_SizeY;

	sf::Texture texture_e;
	
	sf::Sprite enemy[3];
	sf::Sprite enemies;

	sf::Sprite item;
	sf::Sprite item2;

	int type;
	int typeEnemy;
	int typeItem;
	int typeItem2;

	float speed;

	int hp;
	int hpmax;
	int recover;

	int damage;
	int point;

	int addpoint;

	void iniVariation();
	void iniTexture(sf::Sprite sprite);
	//void iniTexture();

public:

	Falling(float pos_x, float pos_y, int i);
	virtual ~Falling();

	void Item(int i);
	void Item2(int i);

	const sf::FloatRect getBound() const;
	const sf::FloatRect getBoundItem() const;
	const sf::FloatRect getBoundItem2() const;

	const  sf::Vector2f& getpos() const;
	const  sf::Vector2f& getposItem() const;
	const  sf::Vector2f& getposItem2() const;

	const  int& getPoint() const;
	const  int& getDamage() const;
	const int& getRecover() const;
	const int& Addpoint() const;

	void update();
	void updateItem();
	void updateItem2();

	void render(sf::RenderTarget* target);
	void renderitem(sf::RenderTarget* target);
	void renderitem2(sf::RenderTarget* target);
};

#endif // !ENEMY_H





