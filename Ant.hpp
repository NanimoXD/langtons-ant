#ifndef ANT_H
#define ANT_H

#include "Direction.hpp"
#include <SFML/System/Vector2.hpp>


/* Definicja mrówki bez graficznej reprezentacji */

class Ant
{
public:
    /* Konstruuje mrówkę skierowaną do góry, w pozycji (0, 0) */
    Ant();

    virtual ~Ant();

    /* Zwraca absolutny kierunek */
    inline Direction currentDirection() const;

    /* Obraca mrówkę relatywnie */
    void rotateAnt(Direction dir);

    /* Ustawia absolutny kierunek mrówki */
    void setDirection(Direction dir);

    /* Pozycja mrówki na planszy (informacja dla obiektu klasy Board) */
    void setPositionOnBoard(const sf::Vector2u &pos);
    inline const sf::Vector2u & positionOnBoard() const;

protected:
    /* Informacja dla klas potomnych, że kierunek się zmienił */
    virtual void directionChanged(Direction previous_direction);

private:
    Direction direction;
    sf::Vector2u board_position;
};


Direction Ant::currentDirection() const
{ return direction; }

inline void Ant::setPositionOnBoard(const sf::Vector2u &pos)
{ board_position = pos; }

const sf::Vector2u & Ant::positionOnBoard() const
{ return board_position; }

#endif // ANT_H
