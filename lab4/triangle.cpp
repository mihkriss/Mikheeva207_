#include "triangle.h"
#include <cmath>

    Triangle::Triangle() {}

    Triangle::Triangle(std::istream &InputStream) 
  {
      InputStream >> a;
      InputStream >> b;
      InputStream >> c;
      InputStream >> d;
      InputStream >> e;
      std:: cout << "Triangle that you wanted to create has been created" << std:: endl;
  }

  void Triangle::Print(std::ostream &OutputStream) {
      OutputStream << "Triangle: ";
      OutputStream << a << " " << b << " " << c << " " << d << " " << e << std:: endl;
      
  }

   size_t Triangle::VertexesNumber() {
       size_t number = 5;
       return number;
   }

   double Triangle::Area() {
   double q = abs(a.X() * b.Y() + b.X() * c.Y() + c.X() * d.Y() + d.X() * e.Y() + e.X() * a.Y() - b.X() * a.Y() - c.X() * b.Y() - d.X() * c.Y() - e.X() * d.Y() - a.X() * e.Y());
   double s = q / 2;
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
        if(p1.a == p2.a && p1.b == p2.b && p1.c == p2.c && p1.d == p2.d && p1.e == p2.e) {
            return true;
        }
        return false;
    }
    
    std::ostream& operator << (std::ostream& os, Triangle& p){
    os << "Triangle: ";
    os << p.a << p.b << p.c << p.d << p.e;
    os << std::endl;
    return os;
}