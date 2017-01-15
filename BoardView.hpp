#ifndef BoardView_hpp
#define BoardView_hpp

#include <SFML/Graphics.hpp>

class BoardView
{
public:
    BoardView(sf::Vector2u pos, sf::Vector2u sizeTex, sf::Vector2u sizeMap, sf::Color color);

    void color(sf::Vector2u pos, sf::Color color);

    sf::Sprite getMap();

private:
    sf::RenderWindow window;

    sf::Sprite sprite;
    sf::Texture texture;
    sf::Image *cell;
};

#endif // BoardView_hpp
