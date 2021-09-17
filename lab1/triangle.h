#include "figure.h"
#include <iostream>

class Triangle : public Figure {
    public:
    Triangle(std:: istream &is);
    size_t VertexesNumber();
    double Area();
    void Print (std:: ostream &os);
    virtual ~Triangle();

    private:
    Point a;
    Point b;
    Point c;
};