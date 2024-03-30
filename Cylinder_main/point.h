#ifndef POINT_H
#define POINT_H
using namespace std;
class Point{
	public:
		Point(int = 0, int = 0);
		void setX(int);
		int getX() const; 
		void setY(int);
		int getY() const; 
		char* getName() const;   // return the class name 
		void print() const;
	private:
		int x;
		int y;
};
#endif

