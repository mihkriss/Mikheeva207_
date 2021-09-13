#include "rectagon.h"
#include <cmath>

Rectagon::Rectagon (std:: istream &is)
{
    is >> a >> b >> c >> d;
        std:: cout << "The rectagon was created" << std:: endl;
}

size_t Rectagon::VertexesNumber() 
{
    return 4;
}

double Rectagon::Area() {
    double RectagonS = abs(a.getX()*b.getY()+b.getX()*c.getY()+c.getX()*d.getY()+d.getX()*a.getY() - a.getY()*b.getX() - b.getY()*c.getX() - c.getY()*d.getX() - d.getY()*a.getX());
    return RectagonS;
}

void Rectagon::Print(std:: ostream &os)
{
    std:: cout << "Rectagon: " << a << " " << b << " " << c << d << std:: endl;
}

Rectagon::~Rectagon() {
    std:: cout << "Rectagon was deleted" << std:: endl;
}
 