#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
public:
    float m_x;
    float m_y;
    float m_radius;

    bool isInside(float x, float y);
};

#endif // CIRCLE_H
