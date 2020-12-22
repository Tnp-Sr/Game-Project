#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<sstream>
#include"Falling.h"
#include"Player.h"
#include "EndGame.h"

class Game
{
private:
	sf::RenderWindow* window;

	float speed = 100, deltaTime = 0.0f;
	sf::Clock clock;

	//player
	Player* player;
	sf::Texture playerTexture;

	//Falling
	std::vector<Falling*> falling;

	float spawnTimer;
	float spawnTimerMax;

	float spawnTimerBuf;
	float spawnTimerMaxBuf;

	//Item
	std::vector<Falling*> items;
	std::vector<Falling*> items2;

	float spawnTimerItem;
	float spawnTimerItemMax;

	float spawnTimerItem2;
	float spawnTimerItemMax2;

	//system
	unsigned Hightscore;
	int point;
	unsigned count = 0;

	//player GUI
	sf::RectangleShape playHPBar;
	sf::RectangleShape playHPBarBack;

	//background
	sf::Texture wordBackgound_t1;
	sf::Texture wordBackgound_t2;
	sf::Texture wordBackgound_t3;
	sf::Texture wordBackgound_t4;

	sf::Sprite wordBackgound_1;
	sf::Sprite wordBackgound_2;
	sf::Sprite sun_s;
	sf::Sprite ground_s;

	//GUI
	sf::Font font;
	sf::Text pointText;

	//SOUND
	sf::SoundBuffer sound1;
	sf::SoundBuffer sound2;
	sf::SoundBuffer sound3;

	sf::Sound star;
	sf::Sound item;
	sf::Sound enemy;


	//ENDGAME
	EndGame* end;

	void iniWindow(sf::RenderWindow* window);
	void iniTexture();

	void iniFalling();
	void iniGUI();

	void iniPlayer();
	void iniWorld();

	void iniSound();
	void iniEndGame();

public:
	Game(sf::RenderWindow *window);
	virtual ~Game();

	//Function
	void run();

	//update
	void updatePollEvent();

	void update();

	void updateFalling();
	void updateitem();
	void updateitem2();

	void updateInput();

	void updateWorld();
	void updateBackground();

	void updatepoint();
	void updateCollision();
	void updateHightscore();

	void updateGUI();


	//draw
	void render();

	void renderFalling();
	void renderPlayer();

	void renderHightscore();
	void renderWorld();
	void renderGUI();


};

