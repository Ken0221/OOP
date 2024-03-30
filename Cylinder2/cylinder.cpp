#include "cylinder.h"
#include <iostream>
#include<iomanip>
#include <cmath>
using namespace std;

Cylinder::Cylinder(int x, int y, double radius, double height) : Circle(x, y, radius), height(height) {}

void Cylinder::setHeight(double height) {
    this->height = height;
}

double Cylinder::getHeight() const {
    return height;
}

double Cylinder::getArea() const {
    return 2 * Circle::getArea() + 2 * M_PI * getRadius() * height;
}

double Cylinder::getVolume() const {
    return Circle::getArea() * height;
}

char* Cylinder::getName() const {
    return "Cylinder";
}

void Cylinder::print() const {
    cout << setprecision(5) << fixed;
    cout << "Class name: " << getName() << endl;
    cout << "(x,y,height):" << (double)Circle::Point::getX() << " , " << (double)Circle::Point::getY() << " , " << getHeight() << endl;
    cout << "(Radius,Cicumference):" << Circle::getRadius() << " , " << Circle::getCircumference() << endl;

    cout << "(Area,Volumn):" << getArea() << " , " << getVolume() << endl << endl;
}

