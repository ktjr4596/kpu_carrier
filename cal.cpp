#include "cal.h"
#include <iostream>


double cal::get_pointx(const double & a, const double & b)
{	
	return (-(pow(b, 2.0) - pow(a, 2.0)) / 20.0);
}

double cal::get_pointy(const double &x, const double &a)
{
	
	return (pow(10, 2.0) - (4 * 1 * (pow(x, 2.0) + (10 * x) + 50 - pow(a, 2.0))));
	
}

double cal::get_angle(const circle& a, const circle& b)
{	
	double x,y,temp,angle;

	x = get_pointx(a.get_dis(), b.get_dis());

	y = get_pointy(x, a.get_dis());
	
	temp = (10 + sqrt(y)) / 2.0;

	angle =atan( (temp / x))*RADIAN_TO_DEGREE;
	
	return angle;
}

