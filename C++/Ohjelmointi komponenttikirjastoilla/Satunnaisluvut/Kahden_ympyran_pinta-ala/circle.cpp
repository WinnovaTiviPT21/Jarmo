#include "circle.h"

bool Circle::isInside(float x, float y) {
    float local_x = x - m_x;
    float local_y = y - m_y;

    return local_x * local_x + local_y * local_y <= m_radius * m_radius;
}
