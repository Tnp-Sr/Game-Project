#include <SFML/Audio.hpp>
#include "WINDOW.h"
#include<time.h>

int main()
{
    sf::SoundBuffer Sound1;
    if (!Sound1.loadFromFile("audio/background.wav"))
    {
        std::cout << "ERROR" << std::endl;
    }

    sf::Sound Sound;

    Sound.setBuffer(Sound1);
    Sound.setVolume(100);
    Sound.setLoop(true);
    Sound.play();

    srand(time(NULL));
    WINDOW game;
    game.run();
}