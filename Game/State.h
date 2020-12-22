#pragma once
#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<stack>
#include"Button.h"
#include "Game.h"

class State
{

private:


protected:

	std::stack<State*>* state;
	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKey;
	std::map<std::string, int> keybinds;
	bool quit;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Resources
	std::map<std::string, sf::Texture> texture;

	//Function
	virtual void iniKeybind() = 0;

public:
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKey, std::stack<State*>* state);
	virtual ~State();

	const bool& getQuit() const;
	void endState();


	virtual void updateMousePosition();
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = NULL) = 0;
};


