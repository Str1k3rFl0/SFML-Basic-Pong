#include <SFML/Graphics.hpp>
#include <iostream>

#include <sstream>
#include <string>

#include "BatPlayer.h"
#include "Ball.h"
#include "Audio.h"

#define MAX_SCORE 3

int main()
{
    // Audio header
    Audio ad;

    // Variables for players name and score
    std::string player[2]{};
    int score[2]{0};

    // Player 1
    std::cout << "Player1 :: ";
    std::getline(std::cin >> std::ws, player[0]);

    // Player 2
    std::cout << "Player2 :: ";
    std::getline(std::cin >> std::ws, player[1]);

    // Create variables for window resolution
    // resolutin(1200, 800)
    const unsigned WINDOW_WIDTH  = 1600;
    const unsigned WINDOW_HEIGHT = 900;
    // Create the window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                            "SFML PONG");
    // Frame limit to 75
    window.setFramerateLimit(75);

    // Create the bat1 and bat2
    BatPlayer batplayer1(5, 15);
    BatPlayer batplayer2(1585, 15);

    // Create the ball
    Ball ball(1600/2, 0);

    // Create the font
    sf::Font font;
    font.loadFromFile("fonts/lightfont.otf");
    // Create the text
    sf::Text playerText[2];
    sf::Text hudText[3];

    // Text for player1
    playerText[0].setFont(font);
    playerText[0].setString(player[0]);
    playerText[0].setCharacterSize(20);
    playerText[0].setFillColor(sf::Color::Green);
    playerText[0].setPosition(20, 20);

    // Text for player2
    playerText[1].setFont(font);
    playerText[1].setString(player[1]);
    playerText[1].setCharacterSize(20);
    playerText[1].setFillColor(sf::Color::Green);
    playerText[1].setPosition(1350, 20);

    // Text for starting the game
    hudText[0].setFont(font);
    hudText[0].setString("Press Enter to Start!\nFirst who score 3 win");
    hudText[0].setCharacterSize(45);
    hudText[0].setFillColor(sf::Color::Cyan);
    sf::FloatRect textRect = hudText[0].getLocalBounds();
    hudText[0].setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    hudText[0].setPosition(1600/2.0f, 900/2.0f);

    // Text for losing the game
    hudText[1].setFont(font);
    hudText[1].setString(" Win the game!");
    hudText[1].setCharacterSize(35);
    hudText[1].setFillColor(sf::Color::Cyan);
    sf::FloatRect textRect2 = hudText[1].getLocalBounds();
    hudText[1].setOrigin(textRect2.left +
        textRect2.width / 2.0f,
        textRect2.top +
        textRect2.height / 2.0f);
    hudText[1].setPosition(1600/2.0f, 900/2.0f);

    hudText[2].setFont(font);
    hudText[2].setString(" Win the game!");
    hudText[2].setCharacterSize(35);
    hudText[2].setFillColor(sf::Color::Cyan);
    sf::FloatRect textRect3 = hudText[2].getLocalBounds();
    hudText[2].setOrigin(textRect3.left +
        textRect3.width / 2.0f,
        textRect3.top +
        textRect3.height / 2.0f);
    hudText[2].setPosition(1600/2.0f, 900/2.0f);

    // Is the game running?
    bool pausedGame = true;

    // Variable for clock
    sf::Clock clock;

    // Running the game
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Handle input for closing the window
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }

        // Handle input for resume game
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        {
            pausedGame = false;
        }

        // Handle buttons for player 1
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            batplayer1.moveUp();
        }
        else
        {
            batplayer1.stopUp();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            batplayer1.moveDown();
        }
        else
        {
            batplayer1.stopDown();
        }

        // Handle buttons for player 2
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            batplayer2.moveUp();
        }
        else
        {
            batplayer2.stopUp();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            batplayer2.moveDown();
        }
        else
        {
            batplayer2.stopDown();
        }

        // Update the game
        sf::Time dt = clock.restart();
        batplayer1.update(dt);
        batplayer2.update(dt);
        ball.update(dt);
        // The HUD
        std::stringstream ss;
        ss << "Player: " << player[0] << "  Score: " << score[0];
        playerText[0].setString(ss.str());

        std::stringstream ss2;
        ss2 << "Player: " << player[1] << "  Score: " << score[1];
        playerText[1].setString(ss2.str());

        std::stringstream playerWin1;
        playerWin1 << player[0] << " Win the game!\nPress ESC to exit";
        hudText[1].setString(playerWin1.str());

        std::stringstream playerWin2;
        playerWin2 << player[1] << " Win the game!\nPress ESC to exit";
        hudText[2].setString(playerWin2.str());

        // Collision for batplayer1
        // top and bottom walls
        // Top wall
        if (batplayer1.getShape().getPosition().y < 0.f)
        {
            batplayer1.colTop();
        }
        // Bottom wall
        if (batplayer1.getShape().getPosition().y +
            batplayer1.getShape().getGlobalBounds().height > 900)
        {
            batplayer1.colDown();
        }

        // Collision for batplayer2
        // top and bottom walls
        // Top wall
        if (batplayer2.getShape().getPosition().y < 0.f)
        {
            batplayer2.colTop();
        }
        // Bottom wall
        if (batplayer2.getShape().getPosition().y +
            batplayer2.getShape().getGlobalBounds().height > 900)
        {
            batplayer2.colDown();
        }

        // Ball collisions
        // Bottom collision
        if (ball.getShape().getPosition().y +
            ball.getShape().getGlobalBounds().height > 900)
        {
            ball.colBottom();

            // Increase the speed
            ball.getSpeed(100.0f);

            // Sound for collision the wall
            ad.getSound();
        }

        // Top collision
        if (ball.getPosition().top < 0)
        {
            ball.colTop();

            // Increase the speed
            ball.getSpeed(100.0f);

            // Sound for collision the wall
            ad.getSound();
        }

        // Left collision
        if (ball.getShape().getPosition().x < 0.f)
        {
            // Reverse the ball
            ball.colLeft();

            // Score for the player 2
            score[1] += 1;

            // Increase the speed by 100.0f
            ball.getSpeed(100.0f);

            // Sound for collision the wall
            ad.getSound();
        }

        // Right collision
        if (ball.getShape().getPosition().x +
            ball.getShape().getGlobalBounds().width > 1600)
        {
            // Reverse the ball
            ball.colRight();

            // Score for the player 1
            score[0] += 1;

            // Increase the speed by 100.0f
            ball.getSpeed(100.0f);

            // Sound for collision the wall
            ad.getSound();
        }

        // Collision between bat and ball
        if (ball.getPosition().intersects(batplayer1.getPosition()))
        {
            ball.colBat();
            // Increase the speed
            ball.getSpeed(10.0f);
        }

        if (ball.getPosition().intersects(batplayer2.getPosition()))
        {
            ball.colBat();
            // Increase the speed
            ball.getSpeed(10.0f);
        }

        // Draw the objects
        window.clear();
        if (pausedGame)
        {
            window.draw(hudText[0]);
        }
        if (!pausedGame)
        {
            window.draw(playerText[0]);
            window.draw(playerText[1]);
            window.draw(batplayer1.getShape());
            window.draw(batplayer2.getShape());
            window.draw(ball.getShape());

            if (score[0] == MAX_SCORE)
            {
                window.draw(hudText[1]);
                ball.getCenterShape(700, 400);
                ball.ballStop();
            }
            if (score[1] == MAX_SCORE)
            {
                window.draw(hudText[2]);
                ball.getCenterShape(700, 400);
                ball.ballStop();
            }
        }
        window.display();

    }

    return 0;
}
