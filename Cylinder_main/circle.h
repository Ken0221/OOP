#ifndef CIRCLE_H
#define CIRCLE_H
#include"point.h"
class Circle : public Point{
	public:
		Circle(int=0, int=0, double =0.0);
		void setRadius(double);
		double getRadius() const; 
		double getDiameter() const;
		double getCircumference() const;
		double getArea() const;
		char* getName() const; //return the class name 
		void print() const;  //return the whole information of this circle  
	private:
		double radius;
};
#endif

