#include "Boss.h"

void Boss::Varible()
{
	this->i = rand() % 2 + 1;

	this->attackCooldownMax = 8.f;
	this->attackCooldown = this->attackCooldownMax;

	this->hpMax = 5000;
	this->hp = this->hpMax;

	this->damage = i;
}

void Boss::iniwindow()
{
}

void Boss::iniBackground()
{
	if (!loadBoss.loadFromFile("img/player/ship3.png"))
	{
		printf("NOT LOAD BOSS");
	}

	this->boss.setTexture(this->loadBoss);
	this->boss.setPosition(0, 5);
	this->boss.setScale(0.6, 0.6);
}

void Boss::setupHp(const int hp)
{
	this->hp = hp;
	if (this->hp < 0)
	{
		this->hp = 0;
	}
}

const int& Boss::getDamage() const
{
	return this->damage;
}

const int& Boss::getHP() const
{
	return this->hp;
}

const int& Boss::getHPMax() const
{
	return this->hpMax;
}

void Boss::setHP(const int Velue)
{
	this->hp = hp;
	if (this->hp < 0)
	{
		this->hp = 0;
	}
}

void Boss::loseHP(const int Velue)
{
	this->hp -= Velue;
}

Boss::Boss()
{
	this->iniBackground();
	this->Varible();
}

Boss::~Boss()
{
}

const sf::Vector2f& Boss::getpos() const
{
	return this->boss.getPosition();
}

const sf::FloatRect Boss::getBound() const
{
	return this->boss.getGlobalBounds();
}

void Boss::update()
{
	this->updateAttack();
	if (this->boss.getPosition().x >= -200)
	{
		this->boss.move(2.f * this->i, 0.f);
		if (this->boss.getPosition().x >= 1200)
		{
			this->boss.setPosition(-200, 5);
		}
	}
}


const bool Boss::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}

	return false;
}

void Boss::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 0.2f;
	}
}

void Boss::render(sf::RenderTarget* target)
{
	target->draw(this->boss);
}

void Boss::render2()
{

}
