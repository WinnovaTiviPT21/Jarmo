#include <iostream>
#include <random>

using namespace std;

class Circle {
public:
    float m_x;
    float m_y;
    float m_radius;

    bool isInside(float x, float y);
};

bool Circle::isInside(float x, float y) {
    float local_x = x - m_x;
    float local_y = y - m_y;

    return local_x * local_x + local_y * local_y <= m_radius * m_radius;
}

int main()
{
    int side = 20;
    mt19937 gen{ 42 };
    uniform_real_distribution<> dist(0, 10);

    float isInside = 0;
    int samples = 10000000;

    Circle c{10.0, 10.0, 5.0};
    for(int i = 0; i < samples; i++) {
        float x = dist(gen);
        float y = dist(gen);

        if (c.isInside(x,y)) {
            isInside++;
        }
    }

    float areaOfSquare = side * side;
    float areaOfCircle = isInside/samples * areaOfSquare;
    cout << "Ympyran pinta-ala " << areaOfCircle << endl;
    return 0;
}
