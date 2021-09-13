#include "figure.h"
#include <iostream>

class Rectagon : public Figure {
    public:
    Rectagon(std:: istream &is);
    size_t VertexesNumber();
    double Area();
    void Print(std:: ostream &os);
    virtual ~Rectagon();

    private:
    Point a;
    Point b;
    Point c;
    Point d;
};