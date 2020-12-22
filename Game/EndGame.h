#include"SFML/Graphics.hpp"
#include<fstream>
#include<sstream>


class EndGame
{
private:
	sf::Font font;
	sf::Text hightscoreText;

	sf::Text pointtText;
	sf::Text pointtText1;
	sf::Text pointtText2;
	sf::Text pointtText3;

	unsigned score;
	unsigned score1;
	unsigned score2;



	sf::Texture bg;
	sf::Sprite bgg;

	void iniText(sf::RenderWindow* window, sf::Text pointt);
	void iniTextBackground(sf::RenderWindow* window);


public:

	EndGame(unsigned score, unsigned hightscore, sf::RenderWindow* window, sf::Text pointt);
	virtual ~EndGame();
	void update(unsigned Hightscore, unsigned point, unsigned c);
	void render(sf::RenderTarget* target);
};

