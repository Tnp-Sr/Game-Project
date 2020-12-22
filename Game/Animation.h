#include<SFML/Graphics.hpp>

class Animation
{
private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	//speed//
	float totalTime;
	float switchTime;

public:
	sf::IntRect uvRect;
	int action[10];

public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);

	void update(int row, float deltaTime, bool faceRight);

};