#ifndef ANT_H
#define ANT_H

#include "Direction.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>


/* Sprite reprezentujący mrówkę, posiadający określone wymiary, teksturę i dodatkowe własności */

class Ant : public sf::Sprite
{
public:
    /* Kierunek Direction jest niezależny od faktycznego kierunku sprita,
     * to znaczy rotate(angle) nie modyfikuje kierunku mrówki na poziomie symulacji */

    /* Konstruuje gotowy sprite z kierunkiem do góry */
    Ant();

    /* Zwraca absolutny kierunek */
    inline Direction currentDirection() const;

    /* Obraca relatywnie. Zmienia kierunek sprita */
    void rotate(Direction dir);

    /* Obraca sprite, jednak nie wpływa na kierunek mrówki w symulacji */
    void rotate(float angle); // aby nie ukryć metody sf::Transformable::rotate

    /* Ustawia absolutny kierunek. Zmienia kierunek sprita */
    void setDirection(Direction dir);

    /* Ustawia teskturę mrówce na tą obecną w klasie. Wywoływana automatycznie w konstruktorze */
    void applyTexture();

private:
    /* Wczytuje teksturę mrówki z pliki, jeżeli jeszcze nie załadowana */
    void loadTexture();

    Direction direction;
    static sf::Texture ant_texture;
};


Direction Ant::currentDirection() const
{ return direction; }

#endif // ANT_H
