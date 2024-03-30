#ifndef CYLINDER_H
#define CYLINDER_H
#include"circle.h"

class Cylinder : public Circle{
	public:
		Cylinder(int = 0, int = 0, double = 0.0, double = 0.0);
		void setHeight(double);
		double getHeight() const; 
		double getArea() const;
		double getVolume() const;
		char* getName() const;  //return the class name
		void print() const;   //return the whole information of this cylinder
	private:
		double height;
};
#endif

