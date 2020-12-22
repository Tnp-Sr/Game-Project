#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKey, std::stack<State*>* state)
{
	this->window = window;
	this->supportedKey = supportedKey;
	this->state = state;
	this->quit = false;
}

State::~State()
{

}

const bool& State::getQuit() const
{
	// TODO: insert return statement here
	return this->quit;
}

void State::endState()
{
	this->quit = true;
}

void State::updateMousePosition()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}


