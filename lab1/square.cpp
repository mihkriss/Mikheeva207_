#include "square.h"
#include <cmath>

Square::Square (std:: istream &is)
{
    is >> a >> b >> c >> d;
    std:: cout << "The square created" << std:: endl;  
}

size_t Square::VertexesNumber() 
{
    return 4;
}

double Square::Area() {
    double SquareS = abs(a.getX()*b.getY()+b.getX()*c.getY()+c.getX()*d.getY()+d.getX()*a.getY() - a.getY()*b.getX() - b.getY()*c.getX() - c.getY()*d.getX() - d.getY()*a.getX());
    return SquareS;
}

void Square::Print(std:: ostream &os)
{
    std:: cout << "Square: " << a << " " << b << " " << c << " " << d << std:: endl;
}

Square::~Square() {
    std:: cout << "Square was deleted" << std:: endl;
}
//x1y2 + x2y3 + x3y4 + x4y1 - y1x2 - y2x3 - y3x4 - y4x1
