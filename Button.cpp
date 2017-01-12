#include "Button.hpp"

// Domyślne ścieżki do czcionki
#define fontSource "font.ttf"
#define reserveFontSource "C:/Windows/Fonts/segoeui.ttf"

// Domyślne ustawienia kolorów
#define defaultColor sf::Color(128, 128, 128)
#define hoverColor sf::Color(160, 160, 160)
#define activeColor sf::Color(192, 192, 192)

void Button::constructor()
{
    setPos(position);
    setSiz(size);
    setDefCol(defaultColor);
    setHovCol(hoverColor);
    setActCol(activeColor);

    sprite.setColor(defaultColor);

    if(!setFon(fontSource))
        setFon(reserveFontSource);
}

void Button::updateSprite()
{
    text.setCharacterSize(size.y * textScale);
    text.setOrigin(-marginLeft, size.y * textScale / 2);
    text.setPosition(position.x, position.y + size.y / 2);

    sprite.setScale(size.x / texture.getSize().x, size.y / texture.getSize().y);
    sprite.setPosition(position);
}

Button::Button():
    marginLeft      (20),
    textScale       (0.3),
    position        (sf::Vector2f(0, 0)),
    size            (sf::Vector2f(0, 0)),
    hover           (false),
    pressed         (false),
    window          (nullptr)
{
    constructor();
}

Button::Button(sf::RenderWindow &win, sf::Vector2f pos, sf::Vector2f siz, std::string str):
    marginLeft      (20),
    textScale       (0.3),
    position        (pos),
    size            (siz),
    hover           (false),
    pressed         (false),
    window          (&win)
{
    setTxt(str);
    constructor();
}

Button::Button(sf::RenderWindow &win, float posx, float posy, float sizx, float sizy, std::string str):
    marginLeft      (20),
    textScale       (0.3),
    position        (sf::Vector2f(posx, posy)),
    size            (sf::Vector2f(sizx, sizy)),
    hover           (false),
    pressed         (false),
    window          (&win)
{
    setTxt(str);
    constructor();
}

bool Button::button(sf::Event &event)
{
    if(event.type == sf::Event::MouseMoved)
    {
        if(event.mouseMove.x > position.x && event.mouseMove.x < position.x + size.x &&
           event.mouseMove.y > position.y && event.mouseMove.y < position.y + size.y)
        {
            if(!hover)
            {
                hover = true;
                sprite.setColor(hovCol);
            }
        }
        else
        {
            if(hover)
            {
                hover = false;
                pressed = false;
                sprite.setColor(defCol);
            }
        }
    }
    else if(hover && !pressed && event.type == sf::Event::MouseButtonPressed)
    {
        pressed = true;

        sprite.setColor(actCol);
    }
    else if(hover && pressed && event.type == sf::Event::MouseButtonReleased)
    {
        pressed = false;

        sprite.setColor(hovCol);

        return true;
    }

    return false;
}

void Button::draw()
{
    if(window == nullptr) return;

    if(texture.getSize() == sf::Vector2u())
    {
        sf::Image img;
        img.create(1, 1, sf::Color(255, 255, 255));
        texture.loadFromImage(img);

        sprite.setTexture(texture);
        updateSprite();
    }

    window->draw(sprite);
    window->draw(text);
}

void Button::setTex(sf::Texture tex)
{
    if(texture.getSize() != sf::Vector2u()) return;

    texture = tex;

    sprite.setTexture(texture);
    updateSprite();
}

void Button::setTex(sf::Image tex)
{
    if(texture.getSize() != sf::Vector2u()) return;

    texture.loadFromImage(tex);

    sprite.setTexture(texture);
    updateSprite();
}

bool Button::setTex(sf::String tex)
{
    if(texture.getSize() != sf::Vector2u() || !texture.loadFromFile(tex))
        return false;

    sprite.setTexture(texture);
    updateSprite();
    return true;
}

void Button::setSiz(sf::Vector2f siz)
{
    size = siz;
    updateSprite();
}

void Button::setSiz(float x, float y)
{
    size = sf::Vector2f(x, y);
    updateSprite();
}

void Button::setPos(sf::Vector2f pos)
{
    position = pos;
    updateSprite();
}

void Button::setPos(float x, float y)
{
    position = sf::Vector2f(x, y);
    updateSprite();
}

void Button::setFon(sf::Font &fon)
{
    font = fon;
}

bool Button::setFon(sf::String fon)
{
    if(!font.loadFromFile(fon))
        return false;

    text.setFont(font);
    return true;
}

void Button::setTxt(sf::Text txt)
{
    text.setString(txt.getString());
    text.setFillColor(txt.getFillColor());
    text.setOutlineColor(txt.getOutlineColor());
    text.setOutlineThickness(txt.getOutlineThickness());
    text.setStyle(txt.getStyle());
}

void Button::setTxt(sf::String txt)
{
    text.setString(txt);
}

void Button::setTxtMrg(short mrg)
{
    marginLeft = mrg;
    updateSprite();
}

void Button::setTxtScl(float y)
{
    textScale = y;
    updateSprite();
}

void Button::setDefCol(sf::Color col)
{
    defCol = col;

    if(!hover) sprite.setColor(defCol);
}

void Button::setDefCol(char r, char g, char b, char a)
{
    setDefCol(sf::Color(r, g, b, a));
}

void Button::setHovCol(sf::Color col)
{
    hovCol = col;

    if(hover && !pressed) sprite.setColor(hovCol);
}

void Button::setHovCol(char r, char g, char b, char a)
{
    setHovCol(sf::Color(r, g, b, a));
}

void Button::setActCol(sf::Color col)
{
    actCol = col;

    if(pressed) sprite.setColor(actCol);
}

void Button::setActCol(char r, char g, char b, char a)
{
    setActCol(sf::Color(r, g, b, a));
}

void Button::setWin(sf::RenderWindow &win)
{
    window = &win;
}

#undef textureSource
#undef fontSource
#undef reserveFontSource

#undef defaultColor
#undef hoverColor
#undef activeColor

#undef marginLeft

















