#include "Audio.h"

sf::Sound Audio::getSound()
{
    m_sound.loadFromFile("audio/sfx-boing9.wav");
    m_soundBoing.setBuffer(m_sound);
    m_soundBoing.setVolume(50.f);
    m_soundBoing.play();

    return m_soundBoing;
}
