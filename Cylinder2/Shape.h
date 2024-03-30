#ifndef SHAPE_H
#define SHAPE_H
#include<string>
using namespace std;
class Shape{
	public:
		virtual double getArea() const;       //return 0.0
	    virtual char* getName() const=0;     //return the class name
	    virtual void print() const=0;          //display data members
};
#endif

