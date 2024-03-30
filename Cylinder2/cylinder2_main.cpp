#include "Shape.h"
#include "point.h"
#include "circle.h"
#include "cylinder.h"
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

void process(Shape* s) {
    cout << fixed << setprecision(5) << "Class name: " << s -> getName() << endl;
    cout << "Area:" << s -> getArea() << endl;
    cout << "The whole print:" << endl;
    s -> print();

    Cylinder* c = dynamic_cast <Cylinder*>(s); // Downcasting
    if (c) {
        cout << "Volume: " << c -> getVolume() << endl;
    }
}

int main() {
    int x, y;
    double r, h;

    while (cin >> x >> y >> r >> h) {
        Point p(x, y);
        Circle c(x, y, r);
        Cylinder cy(x, y, r, h);

        vector<Shape*> shapeVector;
        shapeVector.push_back(&p);
        shapeVector.push_back(&c);
        shapeVector.push_back(&cy);

        for (Shape* s : shapeVector) {
            process(s);
        }

        shapeVector.clear();
    }

    return 0;
}


