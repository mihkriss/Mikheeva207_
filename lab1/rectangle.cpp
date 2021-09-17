#include "rectangle.h"
#include <cmath>

Rectangle::Rectangle (std:: istream &is)
{
    is >> a >> b >> c >> d;
        std:: cout << "The rectagon was created" << std:: endl;
}

size_t Rectangle::VertexesNumber() 
{
    return 4;
}

double Rectangle::Area() {
    double RectangleS = abs(a.getX()*b.getY()+b.getX()*c.getY()+c.getX()*d.getY()+d.getX()*a.getY() - a.getY()*b.getX() - b.getY()*c.getX() - c.getY()*d.getX() - d.getY()*a.getX());
    return RectangleS;
}

void Rectangle::Print(std:: ostream &os)
{
    std:: cout << "Rectangle: " << a << " " << b << " " << c << d << std:: endl;
}

Rectangle::~Rectangle() {
    std:: cout << "Rectangle was deleted" << std:: endl;
}
 