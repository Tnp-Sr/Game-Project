#include "WINDOW.h"

void WINDOW::iniWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1080, 720), "Falling Wish", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(80);
	this->window->setVerticalSyncEnabled(false);
	this->dt = 0.f;
}

void WINDOW::iniState()
{
	this->state.push(new MainMenuState(this->window, &this->supportedKey, &this->state));
}

void WINDOW::iniKey()
{
	this->supportedKey.emplace("Escape", sf::Keyboard::Key::Escape);
}

WINDOW::WINDOW()
{
	this->iniWindow();
	this->iniKey();
	this->iniState();
}

WINDOW::~WINDOW()
{
	delete this->window;

	while (!this->state.empty())
	{
		delete this->state.top();
		this->state.pop();
	}

}

void WINDOW::updateDT()
{
	//update and render one frame
	this->dt = this->dtClock.restart().asSeconds();
}


void WINDOW::updatePollEvent()
{
	//ãªé»ØèÁ»Ô´ Ë¹éÒµèÒ§ window 
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
		{
			this->window->close();
		}

	}
}

void WINDOW::update()
{
	this->updatePollEvent();

	if (!this->state.empty())
	{
		this->state.top()->update(this->dt);

		if (this->state.top()->getQuit())
		{
			this->state.top()->endState();
			delete this->state.top();
			this->state.pop();
		}
	}
	//quit game
	else
	{
		this->window->close();
	}
}

void WINDOW::render()
{
	this->window->clear();

	if (!this->state.empty())
	{
		this->state.top()->render();
	}

	this->window->display();
}

void WINDOW::run()
{
	while (this->window->isOpen())
	{
		//this->updateDT();
		this->update();
		this->render();
	}
}
