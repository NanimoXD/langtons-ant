#include "Direction.h"
#include <cmath>


struct DirectionDbItem
{
    Direction direction;
    float angle;
};

const unsigned int DB_SIZE = 4;

static const DirectionDbItem direction_db[DB_SIZE] = {
    {Direction::Up, 0.0},
    {Direction::Right, 90.0},
    {Direction::Down, 180.0},
    {Direction::Left, 270.0}
};


float getDirectionAngle(Direction direction)
{
    float result = 0.0;

    for (unsigned int i = 0; i < DB_SIZE; ++i) {
        if (direction_db[i].direction == direction) {
            result = direction_db[i].angle;
            break;
        }
    }

    return result;
}

Direction convertAngleToDirection(float angle, bool *ok)
{
    unsigned int a_uint = std::abs(angle);

    if (angle < 0) {
        a_uint = 360 - (a_uint % 360);

        if (a_uint == 360)
            a_uint = 0;
    } else {
        a_uint %= 360;
    }

    float a = a_uint;
    int index = -1;

    for (unsigned int i = 0; i < DB_SIZE; ++i) {
        if (direction_db[i].angle == a) {
            index = i;
            break;
        }
    }

    if (ok)
        *ok = (index != -1);

    return index != -1 ? direction_db[index].direction : Direction::Up; // domyślnie zwracany
}

Direction rotateDirection(Direction source, Direction transformation)
{
    return convertAngleToDirection(getDirectionAngle(source) + getDirectionAngle(transformation));
}
