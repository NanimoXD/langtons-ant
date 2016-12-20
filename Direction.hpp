#ifndef DIRECTION_H
#define DIRECTION_H

/* Podstawowe kierunki w symulacji */

enum Direction {
    Left,
    Right,
    Up,
    Down
};

/* Zwraca odpowiedni kąt kierunkowi. Według wskazówek zegara */
float getDirectionAngle(Direction direction);

/* Próbuje skonwertować kąt (liczbę) na znany kierunek. Obsługuje wartości < 0 i >= 360.
 * Do wartości wskaźnika przypisywany jest wynik true/false operacji */
Direction convertAngleToDirection(float angle, bool *ok = nullptr);

/* Przekształca kierunek "orignal" relatywnie, według kierunku w drugim argumencie. Zwraca ostateczny kierunek */
Direction rotateDirection(Direction source, Direction transformation);

#endif // DIRECTION_H
