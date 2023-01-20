#ifndef BATPLAYER_H
#define BATPLAYER_H

#include <SFML/Graphics.hpp>

class BatPlayer
{
private:
    // Variable for shape
    sf::RectangleShape m_Shape;

    // Position for shape
    sf::Vector2f m_Position;

    // How fast is the bat player?
    float m_BatSpeed { 1200.0f };

    // Variables for moving
    bool m_MovingUp { false };
    bool m_MovingDown { false };

public:
    BatPlayer(float startX, float startY);
    sf::FloatRect getPosition();
    sf::RectangleShape getShape();
    void moveUp();
    void moveDown();
    void stopUp();
    void stopDown();
    void update(sf::Time dt);

    // Collisions
    void colTop();
    void colDown();
};

#endif // BATPLAYER_H
