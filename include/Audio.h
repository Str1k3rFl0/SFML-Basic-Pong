#pragma once
#ifndef AUDIO_H
#define AUDIO_H

#include <SFML/Audio.hpp>

class Audio
{
private:
    sf::SoundBuffer m_sound;
    sf::Sound m_soundBoing;

public:
    sf::Sound getSound();
};

#endif // AUDIO_H
