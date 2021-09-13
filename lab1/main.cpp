#include "figure.h"
#include "triangle.h"
#include "rectagon.h"
#include "square.h"
#include <iostream>


int main () {
    Triangle a (std:: cin);
    std:: cout << "Number of vertices in a triangle:" << " " << a.VertexesNumber() << std:: endl;
    a.Print(std:: cout);
    std:: cout << "Area of a triangle:" << " " << a.Area() << std:: endl;

     

    Square b (std:: cin);
    std:: cout << "Number of vertices for a  square: " << " "<<  b.VertexesNumber() << std:: endl;
    b.Print(std:: cout);
    std:: cout << "Square area:" <<" " << b.Area() << std:: endl;


    Rectagon c (std:: cin);
    std:: cout << "Number of vertices for a rectangle:"<< " " << c.VertexesNumber() << std:: endl;
    c.Print(std:: cout);
    std:: cout << "Rectangle area:"<< " " << c.Area() << std:: endl;

    return 0; 
}