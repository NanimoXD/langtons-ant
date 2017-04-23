#include "Direction2.hpp"

Direction2 rotateDirection2(Direction2 &source, const Direction2 &transformation)
{
    int qubby = source + transformation;
    if(qubby >= 360)
        qubby -= 360;

    source = Direction2(qubby);

    return source;
}
