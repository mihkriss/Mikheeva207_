#include "triangle.h"
#include <cmath>
Triangle::Triangle() {}

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
    this->area = Square;
    return Square;
}

void Triangle::Print(std:: ostream &os)
{
    std:: cout << "Triangle: " << a << " " << b << " " << c << std:: endl;
}

Triangle::~Triangle() {
    std:: cout << "Trianle was deleted" << std:: endl;
}

double Triangle:: GetArea() {
       return area;
   }

bool operator == (Triangle& t1, Triangle& t2){
        if(t1.a == t2.a && t1.b == t2.b && t1.c == t2.c){
            return true;
        }
        return false;
    }
    
std::ostream& operator << (std::ostream& os, Triangle& t){
    os << "Triangle: ";
    os << t.a << t.b << t.c;
    os << std::endl;
    return os;
}