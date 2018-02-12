#ifndef circle_h
#define circle_h
#include "Arduino.h"



class circle
{
public:
	
	circle(int, int, double);

	const int get_x() {
		return x;
	}
	const int get_y() { return y; }
	const double get_dis() { return distance; }
	
	
private:
	const int x;
	 const int y;
	double distance;
	circle & operator=(const circle & rhs);
	circle(const circle & src);


};


#endif