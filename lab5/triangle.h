#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"
#include <iostream>


class Triangle : public Figure {
    public:
    Triangle(std::istream &InputStream);
    Triangle();
    double GetArea();
    size_t VertexesNumber();
    double Area();
    void Print(std::ostream &OutputStream);
    friend bool operator == (Triangle& p1, Triangle& p2);
    friend std::ostream& operator << (std::ostream& os, Triangle& p);
    virtual ~Triangle();
    double area;

    private:
    Point a;
    Point b;
    Point c;
};
#endif
