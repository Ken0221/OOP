#ifndef POINT_H
#define POINT_H
#include "Shape.h"
class Point : public Shape{
	public:
		Point(int=0, int=0);
		void setX(int);
		int getX() const; 
	    void setY(int);
		int getY() const; 
	    char* getName() const;  //return the class name(i.e. “Point”)
	    void print() const;
	private:
		int x;
		int y;
};
#endif

