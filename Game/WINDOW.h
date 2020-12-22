#pragma once
#include"Game.h"
#include"State.h"
#include"MainMenuState.h"


class WINDOW
{
private:
	//window
	sf::RenderWindow* window;
	std::stack<State*> state;

	std::map<std::string, int> supportedKey;
	float dt;
	sf::Clock dtClock;

	void iniWindow();
	void iniState();
	void iniKey();


public:
	WINDOW();
	virtual ~WINDOW();

	void updatePollEvent();
	void updateDT();
	void update();
	void render();
	void run();
};

