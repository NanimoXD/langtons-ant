#ifndef ANTSPRITE_H
#define ANTSPRITE_H

#include "Ant.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>


/* Sprite mrówki, posiadający określone wymiary, teksturę i własności z klasy Ant.
 * Zmiana kierunku mrówki w symulacji - setDirection(), zmienia kierunek sprite-a.
 * setPosition() i przekształcenia sprite-a nie wpływają na mrówkę w symulacji.
 */

class AntSprite : public Ant, public sf::Sprite
{
public:
    /* Konstruuje gotowy sprite z kierunkiem do góry */
    AntSprite();

    /* Ustawia mrówce teskturę na tą obecną w klasie. Wywoływana automatycznie w konstruktorze */
    void applyTexture();

protected:
    void directionChanged(Direction previous_direction);

private:
    /* Wczytuje teksturę mrówki z pliku, jeżeli jeszcze nie załadowana */
    void loadTexture();

    static sf::Texture ant_texture;
};

#endif // ANTSPRITE_H
