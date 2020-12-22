#include "Enemy.h"



void Enemy::iniVariation()
{
	this->pointConut = rand() % 3; //min = 1 max = 5
	this->type = 0;
	this->speed = static_cast<float>(this->pointConut);
	this->hp = this->hpmax;
	this->hpmax = static_cast<float>(this->pointConut);
	this->damage = this->pointConut + 3;
	this->recover = this->pointConut + 3;
	this->point = this->pointConut + 3;
	this->addpoint = this->pointConut + 3;
}

void Enemy::iniTexture(sf::Sprite enemies)
{
	/*this->shape.setRadius(rand() % 20 + 20);
	this->shape.setPointCount(rand() % 20 + 3);
	this->shape.setFillColor(sf::Color(rand()%255+1, rand() % 255 + 1, rand() % 255 + 1, 255));*/

	enemies = this->enemies;

	if (!this->texture_e.loadFromFile("img/player/Anermy2.png"))
	{
		printf("NOT ENEMY 1-5");
	}

	this->typeEnemy = rand() % 3;
	//circle
	if (this->typeEnemy == 1)
	{
		this->enemy[1].setTexture(this->texture_e);
		this->enemy[1].setTextureRect(sf::IntRect(0, 245, 110, 80));

		this->enemies = this->enemy[1];
		this->speed = static_cast<float>(this->pointConut / 2);
	}
	//Red
	if (this->typeEnemy == 2)
	{
		this->enemy[2].setTexture(this->texture_e);
		this->enemy[2].setTextureRect(sf::IntRect(0, 110, 115, 130));

		this->enemies = this->enemy[2];
		this->speed = static_cast<float>(this->pointConut / 2);
	}
	////big stone
	//if (this->typeEnemy == 2)
	//{
	//	this->enemy[2].setTexture(this->texture_e);
	//	this->enemy[2].setTextureRect(sf::IntRect(120,0, 110, 100));

	//	this->enemies = this->enemy[2];
	//	this->speed = static_cast<float>(this->pointConut / 2+2 );
	//}
	//small stone
	if (this->typeEnemy == 0)
	{
		this->enemy[0].setTexture(this->texture_e);
		this->enemy[0].setTextureRect(sf::IntRect(120, 110, 110, 100));

		this->enemies = this->enemy[0];
		this->speed = static_cast<float>(this->pointConut / 2 + 2);
	}
}

Enemy::Enemy(float pos_x, float pos_y, int i)
{
	this->iniVariation();
	this->iniTexture(enemies);
	this->Item(i);
	this->Item2(i);
	//this->iniTexture();
	//this->shape.setPosition(pos_x, pos_y);
	this->enemies.setPosition(pos_x, pos_y);
	this->item.setPosition(pos_x, pos_y);
	this->item2.setPosition(pos_x, pos_y);
}

void Enemy::Item(int i)
{
	this->typeItem = rand() % i;

	if (this->typeItem == 5)
	{
		this->item.setTexture(this->texture_e);
		this->item.setTextureRect(sf::IntRect(230, 0, 100, 70));
		this->speed = static_cast<float>(this->pointConut / 2 + 1);
	}
}

void Enemy::Item2(int i)
{
	this->typeItem2 = rand() % i;

	if (this->typeItem2 == 5)
	{
		this->item2.setTexture(this->texture_e);
		this->item2.setTextureRect(sf::IntRect(330, 0, 100, 70));
		this->speed = static_cast<float>(this->pointConut / 2 + 1);
	}
}

Enemy::~Enemy()
{
}


const sf::FloatRect Enemy::getBound() const
{
	return this->enemies.getGlobalBounds();
}

const sf::FloatRect Enemy::getBoundItem() const
{
	return this->item.getGlobalBounds();
}

const sf::FloatRect Enemy::getBoundItem2() const
{
	return this->item2.getGlobalBounds();
}

const sf::Vector2f& Enemy::getpos() const
{
	return this->enemies.getPosition();
}

const sf::Vector2f& Enemy::getposItem() const
{
	return this->item.getPosition();
}

const sf::Vector2f& Enemy::getposItem2() const
{
	return this->item2.getPosition();
}

const int& Enemy::getPoint() const
{
	return this->point;
}

const int& Enemy::getDamage() const
{
	return this->damage;
}

const int& Enemy::getRecover() const
{
	return this->recover;
}

const int& Enemy::Addpoint() const
{
	return this->addpoint;
}

void Enemy::update()
{
	this->enemies.move(0.f, this->speed);
}

void Enemy::updateItem()
{
	this->item.move(0.f, this->speed);
}

void Enemy::updateItem2()
{
	this->item2.move(0.f, this->speed);
}

void Enemy::render(sf::RenderTarget* target)
{
	//target->draw(this->shape);
	target->draw(this->enemies);
}

void Enemy::renderitem(sf::RenderTarget* target)
{
	target->draw(this->item);
}

void Enemy::renderitem2(sf::RenderTarget* target)
{
	target->draw(this->item2);
}

