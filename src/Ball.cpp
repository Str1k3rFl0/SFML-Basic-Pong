#include "Ball.h"

Ball::Ball(float startX, float startY)
{
    m_Position.x = startX;
    m_Position.y = startY;

    m_Shape.setRadius(8.f);
    m_Shape.setPosition(m_Position);
}

sf::FloatRect Ball::getPosition()
{
    return m_Shape.getGlobalBounds();
}

sf::CircleShape Ball::getShape()
{
    return m_Shape;
}

sf::Vector2f Ball::getCenterShape(float startX, float startY)
{
    m_Position.x = startX;
    m_Position.y = startY;
    m_Shape.setPosition(m_Position);
}

float Ball::getYVelocity()
{
    return m_DirectionY;
}

void Ball::colLeft()
{
    m_Shape.setPosition(0.f, m_Shape.getPosition().y);
    m_DirectionX = -m_DirectionX;
}

void Ball::colRight()
{
    m_Shape.setPosition(1600 - m_Shape.getGlobalBounds().width, m_Shape.getPosition().y);
    m_DirectionX = -m_DirectionX;
}

void Ball::colTop()
{
    m_Shape.setPosition(m_Shape.getPosition().x, 0.f);
    m_DirectionY = -m_DirectionY;
}

void Ball::colBottom()
{
    m_Shape.setPosition(m_Shape.getPosition().x, 900 - m_Shape.getGlobalBounds().height);
    m_DirectionY = -m_DirectionY;
}

void Ball::colBat()
{
    m_DirectionX = -m_DirectionX;
}

float Ball::getSpeed(float speed)
{
    return m_BallSpeed += speed;
}

void Ball::ballStop()
{
    m_DirectionX = 0;
    m_DirectionY = 0;
    m_BallSpeed = 0;
}

void Ball::update(sf::Time dt)
{
    m_Position.y += m_DirectionY * m_BallSpeed * dt.asSeconds();
    m_Position.x += m_DirectionX * m_BallSpeed * dt.asSeconds();

    m_Shape.setPosition(m_Position);
}
