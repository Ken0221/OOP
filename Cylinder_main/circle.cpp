#include "circle.h"
#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

Circle::Circle(int x, int y, double radius) : Point(x, y), radius(radius) {}

void Circle::setRadius(double radius) {
    this -> radius = radius;
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getDiameter() const {
    return 2 * radius;
}

double Circle::getCircumference() const {
    return 2 * M_PI * radius;
}

double Circle::getArea() const {
    return M_PI * radius * radius;
}

char* Circle::getName() const {
    return "Circle";
}

void Circle::print() const {
   cout << "The class of this object is " << getName() << endl;
   cout << "Radius: " << setprecision(3) << fixed << getRadius() << endl;
   cout << "Circumference: " << setprecision(3) << fixed << getCircumference() << endl;
   cout << "Area: " << setprecision(3) << fixed << getArea() << endl << endl;
}

