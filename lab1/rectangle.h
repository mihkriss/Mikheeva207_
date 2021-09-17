#include "figure.h"
#include <iostream>

class Rectangle : public Figure {
    public:
    Rectangle(std:: istream &is);
    size_t VertexesNumber();
    double Area();
    void Print(std:: ostream &os);
    virtual ~Rectangle();

    private:
    Point a;
    Point b;
    Point c;
    Point d;
};