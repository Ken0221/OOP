#include "point.h"
#include <iostream>
#include<cmath>
using namespace std;

Point::Point(int x, int y) : x(x), y(y) {}

void Point::setX(int x) {
    this->x = x;
}

int Point::getX() const {
    return x;
}

void Point::setY(int y) {
    this->y = y;
}

int Point::getY() const {
    return y;
}

char* Point::getName() const {
    return "Point";
}

void Point::print() const {
    cout << "The class of this object is " << getName() << endl;
    cout << "X: " << getX() << endl;
    cout << "Y: " << getY() << endl << endl;
}

