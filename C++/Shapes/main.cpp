#include <iostream>

using namespace std;

class Shape{
public:
    float area();
    float perimeter();
};

// Ympyrä
class Circle : Shape{
    float m_radius;
public:
    Circle(float r);
    float area();
    float perimerer();
};
Circle::Circle(float r){
    m_radius = r;
}
float Circle::area(){
  return 3.14 * m_radius * m_radius;
}
float Circle::perimerer(){
    return 2 * 3.14 * m_radius;
}

// Neliö
class Square : Shape{
    float m_length;
public:
    Square(float l);
    float area();
    float perimerer();
};
Square::Square(float l){
    m_length = l;
}
float Square::area(){
    return m_length * m_length;
}
float Square::perimerer(){
    return 4 * m_length;
}

int main()
{


    cout << "---------------" << endl;
    return 0;
}
