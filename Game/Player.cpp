#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;

	this->iniVariable();

	//Player//
	body.setSize(sf::Vector2f(220.0f, 240.0f));
	body.setPosition(430.f, 420.f);
	body.setTexture(texture);

	//Hitbox//
	playerHitbox.setSize(sf::Vector2f(50.0f, 140.0f));
	playerHitbox.setFillColor(sf::Color::Red);
}

void Player::updateplayer(float deltaTime)
{
	playerHitbox.setPosition(body.getPosition().x+80, body.getPosition().y+60);
	sf::Vector2f movement(0.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (playerHitbox.getPosition().x > 0)
		{
           movement.x -= speed * deltaTime;
		}
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (body.getPosition().x < 910)
		{
			movement.x += speed * deltaTime;
		}
	}


	if (movement.x == 0.0f)
	{
		row = 0;
	}
	else
	{
		row = 1;
		if (movement.x > 0.0f)
		{
			faceRight = true;
		}
		else
		{
			faceRight = false;
		}
	}
	animation.update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);

}

void Player::update1()
{
}

void Player::draw(sf::RenderWindow& window)
{
	//hitbox
	//window.draw(playerHitbox);
	window.draw(body);
}

void Player::iniVariable()
{
	this->hpMax = 100;
	this->hp = this->hpMax;
}

void Player::setupHp(const int hp)
{
	this->hp = hp;
	if (this->hp < 0)
	{
		this->hp = 0;
	}
}


Player::~Player()
{
}

void Player::setPosition(const sf::Vector2f pos)
{
}

void Player::setPosition(const float x, const float y)
{
}

const sf::FloatRect Player::getBound() const
{
	return this->playerHitbox.getGlobalBounds();
}

const int& Player::getHP() const
{
	return this->hp;
}

void Player::getLoseHP()
{
	this->hp = 0;
}

const int& Player::getHPMax() const
{
	return this->hpMax;
}

void Player::loseHP(const int Velue)
{
	this->hp -= Velue;
}

void Player::FillHP(const int Velue)
{
	this->hp += Velue;

	if (this->hp >= this->hpMax)
	{
		this->hp = hpMax;
	}
}
