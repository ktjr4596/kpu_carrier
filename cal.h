#ifndef cal_h
#define cal_h

#include "circle.h"
#include <math.h>
#include <utility>
class cal {
public:

	double get_pointx(const circle &a, const circle &b);
	double get_pointy(const double&, const circle&);
	double get_angle(const double&, const double &);
};
#endif // !cal_h
