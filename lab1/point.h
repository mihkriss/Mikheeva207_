#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
public:
  Point();
  Point(std::istream &is);
  Point(double x, double y);
  friend std:: istream& operator>>(std:: istream& is, Point& p);
  friend std:: ostream& operator<<(std:: ostream& os, Point& p);

double getX();
double getY();

private:
  double x_;
  double y_;
};

#endif