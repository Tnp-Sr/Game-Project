#include "GameState.h"

//ini
void GameState::iniKeybind()
{

	this->keybinds["CLOSE"] = this->supportedKey->at("Escape");

}

void GameState::iniTexture()
{
}

void GameState::iniPlayer()
{
}

//Contruc Destruc
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKey, std::stack<State*>* state)
	: State(window, supportedKey, state)
{
	this->iniKeybind();
	this->iniTexture();
	this->iniPlayer();
	//--------------------------------------
	this->game = new Game(window);
	this->game->run();


}

GameState::~GameState()
{
}

void GameState::updateInput(const float& dt)
{


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
	{
		this->endState();
	}
}

void GameState::update(const float& dt)
{
	this->updateMousePosition();

	this->updateInput(dt);

}

void GameState::render(sf::RenderTarget* target)
{

	if (!target)
	{
		target = this->window;
	}

}