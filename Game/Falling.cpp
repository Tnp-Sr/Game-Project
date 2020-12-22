#include "Falling.h"

void Falling::iniVariation()
{
	//¤Ðá¹¹
	this->pointCount = rand() % 3+3; //min = 3 max = 5

	this->type = 0;
	this->speed = static_cast<float>(this->pointCount);
	this->hp = this->hpmax;
	this->hpmax = static_cast<float>(this->pointCount);
	this->damage = this->pointCount + 3;
	this->recover = this->pointCount + 3;
	this->point = this->pointCount + 3;
	this->addpoint = this->pointCount + 3;
    
}

void Falling::iniTexture(sf::Sprite enemies)
{

	enemies = this->enemies;

	if (!this->texture_e.loadFromFile("img/item.png"))
	{
		printf("Load enemy failed");
	}

	this->e_SizeX = texture_e.getSize().x / 3;
	this->e_SizeY = texture_e.getSize().y / 5;

	this->typeEnemy = rand() % 3;

	//Red_enemy
	if (this->typeEnemy == 0)
	{
		this->enemy[0].setTexture(this->texture_e);
		this->enemy[0].setTextureRect(sf::IntRect(this->e_SizeX*0, this->e_SizeY*1, this->e_SizeX , this->e_SizeY));
		this->enemy[0].setScale(0.8f,0.8f);

		this->enemies = this->enemy[0];
		this->speed = static_cast<float>(this->pointCount / 2);
	}
	//Blue_enemy
	if (this->typeEnemy == 1)
	{
		this->enemy[1].setTexture(this->texture_e);
		this->enemy[1].setTextureRect(sf::IntRect(this->e_SizeX * 1, this->e_SizeY * 1, this->e_SizeX, this->e_SizeY));
		this->enemy[1].setScale(0.8f, 0.8f);

		this->enemies = this->enemy[1];
		this->speed = static_cast<float>(this->pointCount / 2);
	}

	//Green_enemy
	if (this->typeEnemy == 2)
	{
		this->enemy[2].setTexture(this->texture_e);
		this->enemy[2].setTextureRect(sf::IntRect(this->e_SizeX * 2, this->e_SizeY * 1, this->e_SizeX, this->e_SizeY));
		this->enemy[2].setScale(0.8f, 0.8f);

		this->enemies = this->enemy[2];
		this->speed = static_cast<float>(this->pointCount / 2+2 );
	}
}

Falling::Falling(float pos_x, float pos_y, int i)
{
	this->iniVariation();
	this->iniTexture(enemies);
	this->Item(i);
	this->Item2(i);

	this->enemies.setPosition(pos_x, pos_y);
	this->item.setPosition(pos_x, pos_y);
	this->item2.setPosition(pos_x, pos_y);
}

void Falling::Item(int i)//HP+
{
	this->typeItem = rand() % i;

	if (this->typeItem == 3)
	{
		this->item.setTexture(this->texture_e);
		this->item.setTextureRect(sf::IntRect(this->e_SizeX*0, this->e_SizeY * 2, this->e_SizeX, this->e_SizeY));
		this->item.setScale(0.5f, 0.5f);

		this->speed = static_cast<float>(this->pointCount / 2 + 1);
	}
}

void Falling::Item2(int i)//point
{
	this->typeItem2 = rand() % i;

	if (this->typeItem2 == 0)
	{
		this->item2.setTexture(this->texture_e);
		this->item2.setTextureRect(sf::IntRect(this->e_SizeX * 0, this->e_SizeY * 0, this->e_SizeX, this->e_SizeY));
		this->speed = static_cast<float>(this->pointCount / 2 + 1);
	}
}

Falling::~Falling()
{
}


const sf::FloatRect Falling::getBound() const
{
	return this->enemies.getGlobalBounds();
}

const sf::FloatRect Falling::getBoundItem() const
{
	return this->item.getGlobalBounds();
}

const sf::FloatRect Falling::getBoundItem2() const
{
	return this->item2.getGlobalBounds();
}

const sf::Vector2f& Falling::getpos() const
{
	return this->enemies.getPosition();
}

const sf::Vector2f& Falling::getposItem() const
{
	return this->item.getPosition();
}

const sf::Vector2f& Falling::getposItem2() const
{
	return this->item2.getPosition();
}

const int& Falling::getPoint() const
{
	return this->point;
}

const int& Falling::getDamage() const
{
	return this->damage;
}

const int& Falling::getRecover() const
{
	return this->recover;
}

const int& Falling::Addpoint() const
{
	return this->addpoint;
}

void Falling::update()
{
	this->enemies.move(0.f, this->speed);
}

void Falling::updateItem()
{
	this->item.move(0.f, this->speed);
}

void Falling::updateItem2()
{
	this->item2.move(0.f, this->speed);
}

void Falling::render(sf::RenderTarget* target)
{
	//target->draw(this->shape);
	target->draw(this->enemies);
}

void Falling::renderitem(sf::RenderTarget* target)
{
	target->draw(this->item);
}

void Falling::renderitem2(sf::RenderTarget* target)
{
	target->draw(this->item2);
}



