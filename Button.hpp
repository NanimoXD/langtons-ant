#ifndef Button_hpp
#define Button_hpp

namespace jk
{
    class Button
    {
        sf::Font font;
        sf::Text text;
        sf::Texture texture;
        sf::Sprite sprite;
    public:
        Button(sf::RenderWindow &window, sf::Vector2f pos, sf::Vector2f size, std::string str);
    };

    Button::Button(sf::RenderWindow &window, sf::Vector2f pos, sf::Vector2f size, std::string str)
}

#endif // Button_hpp
