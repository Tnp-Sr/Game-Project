#pragma once
#include<SFML/Graphics.hpp>
#include "Animation.h"
#include"Player.h"
class Player
{
private:
	
	sf::RectangleShape body;
	sf::RectangleShape playerHitbox;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
	int hp;
	int hpMax;

	//HP player
	void setupHp(const int hp);
	

public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();

	//position player
	sf::Vector2f GetPosition() { return body.getPosition(); }
	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);


	//position falling
	const sf::FloatRect getBound() const;

    //HP player
	const int& getHP() const;
	void getLoseHP();
	const int& getHPMax() const;
	void loseHP(const int Velue);
	void FillHP(const int Velue);


	//detail player
	void updateplayer(float deltaTime);
	void update1();
	void draw(sf::RenderWindow& window);
	void iniVariable();

};

