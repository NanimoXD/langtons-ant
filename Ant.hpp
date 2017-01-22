#ifndef ANT_H
#define ANT_H

#include "Direction.hpp"
#include <SFML/System/Vector2.hpp>


/* Definicja mrówki w symulacji */

class Ant
{
public:
    /* Konstruuje mrówkę skierowaną do góry, w pozycji (0, 0) */
    Ant();

    explicit Ant(const sf::Vector2u &position, Direction dir = Direction::Up);

    /* Zwraca absolutny kierunek */
    inline Direction getDirection() const;

    /* Obraca mrówkę relatywnie */
    void rotateAnt(Direction dir);

    /* Ustawia absolutny kierunek mrówki */
    void setDirection(Direction dir);

    /* Pozycja mrówki na planszy (informacja dla obiektu klasy Board) */
    void setPosition(const sf::Vector2u &position);
    inline const sf::Vector2u & getPosition() const;

private:
    Direction direction;
    sf::Vector2u on_board_position;
};


Direction Ant::getDirection() const
{ return direction; }

inline void Ant::setDirection(Direction dir)
{ direction = dir; }

inline void Ant::setPosition(const sf::Vector2u &position)
{ on_board_position = position; }

const sf::Vector2u & Ant::getPosition() const
{ return on_board_position; }

#endif // ANT_H
