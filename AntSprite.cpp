#include "AntSprite.hpp"
#include <iostream>


sf::Texture AntSprite::ant_texture = sf::Texture();


AntSprite::AntSprite()
    : Ant(),
      sf::Sprite()
{
    loadTexture();
    applyTexture();
}

void AntSprite::applyTexture()
{
    setTexture(ant_texture);
}

void AntSprite::directionChanged(Direction previous_direction)
{
    rotate(getDirectionAngle(currentDirection()) - getDirectionAngle(previous_direction));
}

void AntSprite::loadTexture()
{
    if (ant_texture.getSize() == sf::Vector2u()) {
        if (!ant_texture.loadFromFile("Images/ant.png"))
            std::cout << "Załadowanie tesktury mrówki nie powiodło się" << std::flush;
    }
}
