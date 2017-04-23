#ifndef DIRECTION_H
#define DIRECTION_H

/* Podstawowe kierunki w symulacji */

enum Direction2 {
    Left = 270,
    Right = 90,
    Up = 0,
    Down = 180
};

/* Przekształca kierunek "orignal" relatywnie, według kierunku w drugim argumencie. Zwraca ostateczny kierunek */
Direction2 rotateDirection2(Direction2 &source, const Direction2 &transformation);

#endif // DIRECTION_H
