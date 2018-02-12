#include "cal.h"


double cal::get_pointx(const circle & a, const circle & b)
{	double x;
	
	x = -(pow((const_cast<circle &>(b)).get_dis(), 2.0) - pow((const_cast<circle &>(a)).get_dis(), 2.0)) / 20.0;


	return x;
}

double cal::get_pointy(const double &x, const circle &a)
{
	double y, y1;
	y = pow(10, 2.0) - (4 * 1 * (pow(x, 2.0) + (10 * x) + 50 - pow((const_cast<circle &>(a)).get_dis(), 2.0)));
	y1 = (10 + sqrt(y)) / 2.0;
	return y1;
	
}

double cal::get_angle(const double &x, const double &y)
{
	double temp =atan( y / x);
	
	return temp;
}

