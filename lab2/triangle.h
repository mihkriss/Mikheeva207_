#include "figure.h"
#include <iostream>
#ifndef TRIANGLE_H
#define TRIANGLE_H
class Triangle : public Figure {
    public:
    Triangle(std:: istream &is);
    Triangle();
    size_t VertexesNumber();
    double Area();
    double GetArea();
    void Print (std:: ostream &os);
    virtual ~Triangle();
    friend bool operator == (Triangle& t1, Triangle& t2);
    friend std::ostream& operator << (std::ostream& os, Triangle& t);
    double area;

    private:
    Point a;
    Point b;
    Point c;
};
#endif