#include"Game.h"

//INI
void Game::iniWindow(sf::RenderWindow *window)
{
	this->window = window;
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void Game::iniTexture() //loadtexture
{
	if (!this->playerTexture.loadFromFile("ch/player.png"))
	{
		printf("Load player failed");
	}

}

void Game::iniFalling()
{
	//enermy
	this->spawnTimerMax = 20.f;
	this->spawnTimer = this->spawnTimerMax;

	//hp+
	this->spawnTimerItemMax = 5.f;
	this->spawnTimerItem = this->spawnTimerItemMax;

	//star
	this->spawnTimerItemMax2 = 5.f;
	this->spawnTimerItem2 = this->spawnTimerItemMax2;


}

void Game::iniGUI()
{
	if (!this->font.loadFromFile("font/FC Motorway Semi-condensed Regular.otf"))
		printf("NOT LOAD FONT");

	//inipoint
	this->pointText.setFont(font);
	this->pointText.setFillColor(sf::Color(25,25,25,500));
	this->pointText.setCharacterSize(30);
	this->pointText.setPosition(this->window->getSize().x - 150, 0);
	this->pointText.setString("SCORE");

	//update player
	this->playHPBar.setSize(sf::Vector2f(300.f, 25.f));
	this->playHPBar.setFillColor(sf::Color(25, 25, 250, 500));
	this->playHPBar.setPosition(sf::Vector2f(40, 10));

}

void Game::iniPlayer()
{
	this->player = new Player(&playerTexture, sf::Vector2u(15, 3), 0.1f, 250.0f);
}

void Game::iniWorld()
{
	if (!this->wordBackgound_t1.loadFromFile("bg/b1.png"))
	{
		printf("NOT LOAD BACKGROUND");
	}
	if (!this->wordBackgound_t2.loadFromFile("bg/b2.png"))
	{
		printf("NOT LOAD BACKGROUND2");
	}
	if (!this->wordBackgound_t3.loadFromFile("bg/sun.png"))
	{
		printf("NOT LOAD SUN");
	}
	if (!this->wordBackgound_t4.loadFromFile("bg/ground.png"))
	{
		printf("NOT LOAD GROUND");
	}


	this->wordBackgound_1.setTexture(this->wordBackgound_t1);
	this->wordBackgound_2.setTexture(this->wordBackgound_t2);
	this->sun_s.setTexture(this->wordBackgound_t3);
	this->ground_s.setTexture(this->wordBackgound_t4);

	this->wordBackgound_1.setScale((float)this->window->getSize().x / this->wordBackgound_t1.getSize().x, (float)this->window->getSize().y / this->wordBackgound_t1.getSize().y);
	this->wordBackgound_2.setScale((float)this->window->getSize().x / this->wordBackgound_t2.getSize().x, (float)this->window->getSize().y / this->wordBackgound_t2.getSize().y);
	this->sun_s.setScale(0.75f, 0.75f);
}

void Game::iniSound()
{
	if(!this->sound1.loadFromFile("audio/score2.wav"))
	{
		printf("NOT LOAD SOUND1");
	}
	if (!this->sound2.loadFromFile("audio/item.wav"))
	{
		printf("NOT LOAD SOUND2");
	}
	if (!this->sound2.loadFromFile("audio/hit.wav"))
	{
		printf("NOT LOAD SOUND3");
	}
	this->star.setBuffer(this->sound1);
	this->item.setBuffer(this->sound2);
	this->enemy.setBuffer(this->sound3);


}

void Game::iniEndGame()
{
	this->end = new EndGame(this->point, this->Hightscore, this->window, this->pointText);
}

Game::Game(sf::RenderWindow* window)
{
	this->iniTexture();

	this->iniWindow(window);
	
	this->iniFalling();

	this->iniSound();

	this->iniWorld();

	this->iniGUI();
	
	this->iniPlayer();

	this->iniEndGame();

}

Game::~Game()
{
	for (auto* i : this->falling)
	{
		delete i;
	}
	for (auto* i : this->items)
	{
		delete i;
	}
	for (auto* i : this->items2)
	{
		delete i;
	}
}

void Game::run()
{
	while (this->window->isOpen())
	{

		this->updatePollEvent();

			this->player->updateplayer(this->deltaTime);

			this->update();
			//draw//
			this->render();
	}
	    	
}

//UPDATE
void Game::updatePollEvent()
{
	//ใช้ปุ่มปิด หน้าต่าง window 
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
		{
			this->window->close();
		}
		//ปุ่ม
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
		{
			this->window->close();
		}

	}
}


void Game::update()
{
	this->updateInput();
	if (this->point <= 0)
	{
		this->player->update1();
	}

	this->updateCollision();

	this->updateFalling();
	this->updateitem();
	this->updateitem2();

	this->updateHightscore();
	this->updateGUI();

	this->updateBackground();
	this->updateWorld();
	this->updatepoint();
}

void Game::updateFalling()
{
	//spawn

	if (this->point >= 100 && point < 250)
	{
		this->spawnTimer += .5f;
		if (this->spawnTimer >= this->spawnTimerMax)
		{
			this->falling.push_back(new Falling(rand() % this->window->getSize().x - 100, -200.f, 100));
			this->spawnTimer = 0.f;
		}
	}
	else if (this->point >= 250 && point < 500)
	{
		this->spawnTimer += .7f;
		if (this->spawnTimer >= this->spawnTimerMax)
		{
			this->falling.push_back(new Falling(rand() % this->window->getSize().x - 100, -200.f, 100));
			this->spawnTimer = 0.f;
		}
	}
	else if (this->point > 500)
	{
		this->spawnTimer += 1.f;
		if (this->spawnTimer >= this->spawnTimerMax)
		{
			this->falling.push_back(new Falling(rand() % this->window->getSize().x - 100, -200.f, 150));
			this->spawnTimer = 0.f;
		}
	}
	else
	{
		this->spawnTimer += .3f;
		if (this->spawnTimer >= this->spawnTimerMax)
		{
			this->falling.push_back(new Falling(rand() % this->window->getSize().x - 100, -200.f, 100));
			this->spawnTimer = 0.f;
		}
	}


	//update
	unsigned counter = 0;
	for (auto* Falling : this->falling)
	{
		Falling->update();

		//เลย screen
		if (Falling->getBound().top > this->window->getSize().y)
		{
			//delete enemy			
			delete this->falling.at(counter);
			this->falling.erase(this->falling.begin() + counter);
		}

		//เช็คชนแล้วเลือดลด
		if (Falling->getBound().intersects(this->player->getBound()))
		{
			this->enemy.play();
			this->player->loseHP(this->falling.at(counter)->getDamage());

			delete this->falling.at(counter);
			this->falling.erase(this->falling.begin() + counter);
			
		}
		counter++;
	}
}

void Game::updateitem()
{

	if (this->point >100 )
	{
		this->spawnTimerItem += 0.5f;
		if (this->spawnTimerItem >= this->spawnTimerItemMax)
		{
			this->items.push_back(new Falling(rand() % this->window->getSize().x - 100, -200.f, 70));
			this->spawnTimerItem = 0.f;
		}
	}
	else 
	{
		this->spawnTimerItem += 0.4f;
		if (this->spawnTimerItem >= this->spawnTimerItemMax)
		{
			this->items.push_back(new Falling(rand() % this->window->getSize().x - 100, -200.f, 50));
			this->spawnTimerItem = 0.f;
		}
	}


	//update
	unsigned counter = 0;
	for (auto* Falling1 : this->items)
	{
		Falling1->updateItem();

		//เลย screen
		if (Falling1->getBound().top > this->window->getSize().y)
		{
			//delete enemy			
			delete this->items.at(counter);
			this->items.erase(this->items.begin() + counter);
		}

		//เช็คชนแล้วเลือดเพิ่ม
		if (Falling1->getBoundItem().intersects(this->player->getBound()))
		{
			//this->item.play();
			this->player->FillHP(this->items.at(counter)->getDamage());

			delete this->items.at(counter);
			this->items.erase(this->items.begin() + counter);
			//hp
		}

		counter++;
	}
}

void Game::updateitem2()
{
	//spawn
	if (this->point > 500)
	{
		this->spawnTimerItem2 += .7f;
		if (this->spawnTimerItem2 >= this->spawnTimerItemMax2)
		{
			this->items2.push_back(new Falling(rand() % this->window->getSize().x - 100, -200.f, 20));
			this->spawnTimerItem2 = 0.f;
		}
	}
	else
	{
	this->spawnTimerItem2 += .5f;
	if (this->spawnTimerItem2 >= this->spawnTimerItemMax2)
	{
		this->items2.push_back(new Falling(rand() % this->window->getSize().x - 100, -200.f, 10));
		this->spawnTimerItem2 = 0.f;
	}
	}
	

	//update
	unsigned counter = 0;
	for (auto* Falling2 : this->items2)
	{
		Falling2->updateItem2();

		//เลย screen
		if (Falling2->getBoundItem2().top > this->window->getSize().y)
		{
			//delete enemy			
			delete this->items2.at(counter);
			this->items2.erase(this->items2.begin() + counter);
		}

		//เช็คชนแล้วคะแนนเพิ่ม
		if (Falling2->getBoundItem2().intersects(this->player->getBound()))
		{
			this->star.play();
			this->point += Falling2->getPoint();
			delete this->items2.at(counter);
			this->items2.erase(this->items2.begin() + counter);
			//hp
		}
		counter++;
	}
}

void Game::updateInput()
{
}

void Game::updateWorld()
{
	this->sun_s.setPosition(440, 120);
	this->ground_s.setPosition(0, 0);
}

void Game::updateBackground()
{
	this->deltaTime = clock.restart().asSeconds();

	this->wordBackgound_2.setPosition(this->wordBackgound_1.getPosition().x - 1080, 0);

	if (this->wordBackgound_1.getPosition().x > 1080)
		this->wordBackgound_1.setPosition(0, this->wordBackgound_2.getPosition().x);

	if (this->wordBackgound_2.getPosition().x > 1080)
		this->wordBackgound_2.setPosition(0, this->wordBackgound_1.getPosition().x);

	//ขยับไปโดย ระยะทาง = ความเร็ว * เวลาที่เปลี่ยนไป

	this->wordBackgound_1.move(this->speed * this->deltaTime, 0);
	this->wordBackgound_2.move(this->speed * this->deltaTime, 0);

}

void Game::updatepoint()
{
	if (this->point < 0)
	{
		this->point = 0;
	}
}

void Game::updateCollision()
{
}

void Game::updateHightscore()
{
	this->end->update(this->Hightscore, this->point, this->count);

}

void Game::updateGUI()
{
	//เลขคะแนน
	std::stringstream ss;
	ss << "SCORE : " << this->point;
	this->pointText.setString(ss.str());

	//update player
	float hpPercent = static_cast<float>(this->player->getHP()) / this->player->getHPMax() * 100;
	this->playHPBar.setSize(sf::Vector2f(4.f * hpPercent, this->playHPBar.getSize().y));
}

//RENDER
void Game::render()
{
	//เริ่มวาด
	this->window->clear();

	this->renderWorld();
	this->renderPlayer();
	this->renderFalling();
	this->renderGUI();
	
	//Game over
	if (this->player->getHP() <= 0)
	{
		this->window->clear();
		this->renderHightscore();
	}

	//สิ้นสุด
	this->window->display();
}

void Game::renderFalling()
{
	for (auto* Falling2 : this->items2)
	{
		Falling2->renderitem2(this->window);
	}
	
	for (auto* Falling : this->falling)
	{
		Falling->render(this->window);
	}

	for (auto* Falling1 : this->items)
	{
		Falling1->renderitem(this->window);
	}

	
}

void Game::renderPlayer()
{
	this->player->draw(*this->window);
}

void Game::renderHightscore()
{
	this->end->render(this->window);

}

void Game::renderWorld()
{
	this->window->draw(this->wordBackgound_1);
	this->window->draw(this->wordBackgound_2);
	this->window->draw(this->sun_s);
	this->window->draw(this->ground_s);
}

void Game::renderGUI()
{
	this->window->draw(this->pointText);
	this->window->draw(this->playHPBarBack);
	this->window->draw(this->playHPBar);
}

