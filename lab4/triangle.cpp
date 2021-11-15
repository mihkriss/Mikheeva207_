#include "triangle.h"
#include <cmath>

    Triangle::Triangle() {}

    Triangle::Triangle(std::istream &InputStream) 
  {
      InputStream >> a;
      InputStream >> b;
      InputStream >> c;
      std:: cout << "Triangle that you wanted to create has been created" << std:: endl;
  }

  void Triangle::Print(std::ostream &OutputStream) {
      OutputStream << "Triangle: ";
      OutputStream << a << " " << b << " " << c << std:: endl;
      
  }

   size_t Triangle::VertexesNumber() {
       size_t number = 5;
       return number;
   }

   double Triangle::Area() {
    double s = 0.5 * abs(a.getX() * b.getY() + b.getX() * c.getY() + c.getX() * a.getY() - a.getY() * b.getX() - b.getY() * c.getX() - c.getY() * a.getX());

   this->area = s;
   return s;
   }

   double Triangle:: GetArea() {
       return area;
   }

    Triangle::~Triangle() {
          std:: cout << "My friend, your triangle has been deleted" << std:: endl;
      }

    bool operator == (Triangle& p1, Triangle& p2){
        if(p1.a == p2.a && p1.b == p2.b && p1.c == p2.c) {
            return true;
        }
        return false;
    }
    
    std::ostream& operator << (std::ostream& os, Triangle& p){
    os << "Triangle: ";
    os << p.a << p.b << p.c;
    os << std::endl;
    return os;
}
