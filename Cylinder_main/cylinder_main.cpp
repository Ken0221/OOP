#include "point.h"
#include "circle.h"
#include "cylinder.h"
#include <iostream>
using namespace std;

int main()
{
    int x, y;
    double r, h;
    Point point(10,10);
    Circle circle(20,20,20);
    Cylinder cylinder(30,30,30,30);
    
    point.print();
    circle.print();
    cylinder.print();

    cout<<"Enter data of class Point:";
    cin>>x>>y;
    point.setX(x);
    point.setY(y);

    cout<<"Enter data of class Circle:";
    cin>>x>>y>>r;
    circle.setX(x);
    circle.setY(y);
    circle.setRadius(r);

    cout<<"Enter data of class Cylinder:";
	cin>>x>>y>>r>>h;
    cylinder.setX(x);
    cylinder.setY(y);
    cylinder.setRadius(r);
    cylinder.setHeight(h);

    point.print();
    circle.print();
    cylinder.print();

    return 0;
}

