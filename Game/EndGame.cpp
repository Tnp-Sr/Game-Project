#include "EndGame.h"

void EndGame::iniText(sf::RenderWindow* window, sf::Text pointt)
{

	//load font
	if (!font.loadFromFile("font/FC Motorway Semi-condensed Regular.otf"))
		printf("NOT LOAD FONT");

	//ini hightscoreText
	this->hightscoreText.setFont(this->font);
	this->hightscoreText.setCharacterSize(40);
	this->hightscoreText.setPosition(window->getSize().x / 2.5f - this->hightscoreText.getGlobalBounds().width / 2.f, window->getSize().y / 2.f - this->hightscoreText.getGlobalBounds().height / 2.f - 20);
	this->hightscoreText.setString("HightScore");

	//score
	pointt.setCharacterSize(40);
	pointt.setPosition(window->getSize().x / 2.5f - this->hightscoreText.getGlobalBounds().width / 2.f + 80, window->getSize().y / 2.f - this->hightscoreText.getGlobalBounds().height / 2.f - 80);
	this->pointtText = pointt;

	//score1
	this->pointtText1.setFont(this->font);
	this->pointtText1.setCharacterSize(40);
	this->pointtText1.setPosition(window->getSize().x / 2.5f - this->hightscoreText.getGlobalBounds().width / 2.f, window->getSize().y / 2.f - this->hightscoreText.getGlobalBounds().height / 2.f - 120);
	this->pointtText1.setString("pointtText1");


}

void EndGame::iniTextBackground(sf::RenderWindow* window)
{
	if (!this->bg.loadFromFile("bg/End.png"))
	{
		printf("NOT LOAD BG High");
	}

	this->bgg.setTexture(this->bg);

}

EndGame::EndGame(unsigned score, unsigned hightscore, sf::RenderWindow* window, sf::Text pointt)
{
	iniText(window, pointt);
	iniTextBackground(window);
}

EndGame::~EndGame()
{

}

void EndGame::update(unsigned Hightscore, unsigned point, unsigned c)
{

	//Hight score
	std::ifstream readHightscore;
	readHightscore.open("score/highscore.text");
	if (readHightscore.is_open())
	{
		while (!readHightscore.eof())
		{
			readHightscore >> Hightscore;
		}
	}
	readHightscore.close();

	std::ofstream writeHightscore("score/highscore.text");
	if (writeHightscore.is_open())
	{
		if (point > Hightscore)
		{
			Hightscore = point;
		}
		writeHightscore << Hightscore;
	}
	writeHightscore.close();

	//score

	std::ifstream readscore;
	readscore.open("score/score_play.text");
	if (readscore.is_open())
	{
		while (!readHightscore.eof())
		{
			readHightscore >> this->score;
		}
	}
	readHightscore.close();

	std::ofstream writescore("score/score_play.text");
	if (writescore.is_open())
	{
			this->score = point;
		writescore << this->score;
	}
	writeHightscore.close();

	std::stringstream dd;
	dd << "HIGHSCORE : " << Hightscore;
	this->hightscoreText.setString(dd.str());

	std::stringstream ss;
	ss << "SCORE : " << point;
	this->pointtText.setString(ss.str());

}

void EndGame::render(sf::RenderTarget* target)
{
	target->draw(this->bgg);
	target->draw(this->hightscoreText);
	target->draw(this->pointtText);
}
