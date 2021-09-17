#include "triangle.h"
#include <cmath>

Triangle::Triangle(std:: istream &is)
{
    is >> a >> b >> c;
    std:: cout << "The triangle was created" << std:: endl;
}

size_t Triangle::VertexesNumber() 
{
    return 3;
}

double Triangle::Area() {
    double Square = 0.5 * abs(a.getX() * b.getY() + b.getX() * c.getY() + c.getX() * a.getY() - a.getY() * b.getX() - b.getY() * c.getX() - c.getY() * a.getX());
    return Square;
}

void Triangle::Print(std:: ostream &os)
{
    std:: cout << "Triangle: " << a << " " << b << " " << c << std:: endl;
}

Triangle::~Triangle() {
    std:: cout << "Trianle was deleted" << std:: endl;
}
