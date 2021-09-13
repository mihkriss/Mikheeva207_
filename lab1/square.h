#include "figure.h"
#include <iostream>

class Square : public Figure {
    public:
    Square(std:: istream &is);
    size_t VertexesNumber();
    double Area();
    void Print (std:: ostream &os);
    virtual ~Square();

    private:
    Point a;
    Point b;
    Point c;
    Point d;
};