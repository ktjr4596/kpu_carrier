#ifndef cal_h
#define cal_h

#include "circle.h"
#include <math.h>

const static double RADIAN_TO_DEGREE = 180 / 3.141592654;

class cal {
public:

	double get_pointx(const double &a, const double &b);
	double get_pointy(const double&, const double &);
	double get_angle(const circle&, const circle &);
};
#endif // !cal_h
