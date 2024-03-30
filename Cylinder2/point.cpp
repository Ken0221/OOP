#include "point.h"
#include <iostream>
#include<iomanip>
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
    cout << setprecision(5) << fixed;
    cout << "Class name: " << getName() << endl;
    cout << "(x,y):" << (double)getX() << " , " << (double)getY() << endl;
    cout << "Area:" << 0.00000 << endl << endl;
}

