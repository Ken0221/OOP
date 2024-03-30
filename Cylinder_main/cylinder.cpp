#include "cylinder.h"
#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

Cylinder::Cylinder(int x, int y, double radius, double height) : Circle(x, y, radius), height(height) {}

void Cylinder::setHeight(double height) {
    this -> height = height;
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
    cout << "The class of this object is" << getName() << endl;
    cout << "Radius: " << setprecision(3) << fixed << Circle::getRadius() << endl;
    cout << "Height: " << setprecision(3) << fixed << getHeight() << endl;
    cout << "Area: " << setprecision(3) << fixed << getArea() << endl;
    cout << "Volumn: " << setprecision(3) << fixed << getVolume() << endl << endl;
}

