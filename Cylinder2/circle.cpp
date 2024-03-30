#include "circle.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

Circle::Circle(int x, int y, double radius) : Point(x, y), radius(radius) {}

void Circle::setRadius(double radius) {
    this->radius = radius;
}

double Circle::getRadius() const {
    return radius;
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
    cout << setprecision(5) << fixed;
    cout << "Class name: " << getName() << endl;
    cout << "(x,y):" << (double)Point::getX() << " , " << (double)Point::getY() << endl;
    cout << "(Radius,Cicumference):" << getRadius() << " , " << getCircumference() << endl;
    cout << "Area:" << getArea() << endl << endl;
}

