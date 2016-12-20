#include "Ant.hpp"
#include <iostream>


sf::Texture Ant::ant_texture = sf::Texture();

Ant::Ant()
    : sf::Sprite(),
      direction(Direction::Up)
{
    loadTexture();
    applyTexture();
}

void Ant::rotate(Direction dir)
{
    direction = rotateDirection(direction, dir);
    rotate(getDirectionAngle(dir));
}

void Ant::rotate(float angle)
{
    dynamic_cast<sf::Transformable *>(this)->rotate(angle);
}

void Ant::setDirection(Direction dir)
{
    rotate(getDirectionAngle(dir) - getDirectionAngle(direction));
    direction = dir;
}

void Ant::applyTexture()
{
    setTexture(ant_texture);
}

void Ant::loadTexture()
{
    if (ant_texture.getSize() == sf::Vector2u()) {
        if (!ant_texture.loadFromFile("Images/ant.png"))
            std::cout << "Załadowanie tesktury mrówki nie powiodło się" << std::flush;
    }
}
