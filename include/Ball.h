#pragma once
#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball
{
private:
    // Create the ball
    sf::CircleShape m_Shape;

    // How fast is the ball
    float m_BallSpeed = 700.0f ;

    // Set the position for shape
    sf::Vector2f m_Position;

    // Variable for velocity
    float m_DirectionX = .4f;
    float m_DirectionY = .4f;

public:
    Ball(float startX, float startY);
    sf::FloatRect getPosition();
    sf::CircleShape getShape();
    sf::Vector2f getCenterShape(float startX, float startY);
    float getYVelocity();
    void colRight();
    void colLeft();
    void colTop();
    void colBottom();
    void colBat();
    float getSpeed(float speed);
    void ballStop();
    void update(sf::Time dt);
};

#endif // BALL_H
