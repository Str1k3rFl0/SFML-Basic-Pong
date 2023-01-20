#include "BatPlayer.h"

// Constructor
BatPlayer::BatPlayer(float startX, float startY)
{
    m_Position.x = startX;
    m_Position.y = startY;

    m_Shape.setSize(sf::Vector2f(10, 90));
    m_Shape.setPosition(m_Position);
}

// Return position of the shape
sf::FloatRect BatPlayer::getPosition()
{
    return m_Shape.getGlobalBounds();
}

// Return the shape
sf::RectangleShape BatPlayer::getShape()
{
    return m_Shape;
}

// Collision for top
void BatPlayer::colTop()
{
    m_Shape.setPosition(m_Shape.getPosition().x, 0.f);
}

// Collision for Down
void BatPlayer::colDown()
{
    m_Shape.setPosition(m_Shape.getPosition().x, 900 - m_Shape.getGlobalBounds().height);
}

// Movement functions
void BatPlayer::moveDown()
{
    m_MovingDown = true;
}

void BatPlayer::moveUp()
{
    m_MovingUp = true;
}

void BatPlayer::stopDown()
{
    m_MovingDown = false;
}

void BatPlayer::stopUp()
{
    m_MovingUp = false;
}

void BatPlayer::update(sf::Time dt)
{
    if (m_MovingDown)
    {
        m_Position.y += m_BatSpeed * dt.asSeconds();
    }
    if (m_MovingUp)
    {
        m_Position.y -= m_BatSpeed * dt.asSeconds();
    }

    m_Shape.setPosition(m_Position);
}
