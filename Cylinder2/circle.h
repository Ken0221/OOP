#ifndef CIRCLE_H
#define CIRCLE_H
#include"point.h"
class Circle : public Point{
	public:
		Circle(int=0, int=0, double r=0.0);
		void setRadius(double);
		double getRadius() const;      //半徑
	    double getCircumference() const; //圓周長
	    double getArea() const;
	    char* getName() const;  //return the class name(i.e. “Circle”)
	    void print() const;
	private:
		double radius;
};
#endif

