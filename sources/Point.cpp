#include <math.h>
#include "Point.hpp"

namespace ariel{

    //constructors
    Point::Point() : _x(0.0), _y(0.0) {}

    Point::Point(double _x, double _y): _x(_x), _y(_y){}

    // dist= sqrt[((x2-x1)^2)+((y2-y1)^2)]
    double Point::distance(Point other)const{
        return sqrt(pow(this->_x - other._x,2) + pow(this->_y - other._y,2));
    }

    double Point::getX() const{
        return _x;
    }

    double Point::getY() const{
        return _y;
    }

    Point Point::moveTowards(const Point &curr, const Point &other, double dist){
	// error
    if (dist < 0)
		throw invalid_argument("Distance cannot be negative!");

	if (curr.distance(other) <= dist)
		return other;

    // dist= sqrt[((x2-x1)^2)+((y2-y1)^2)]
    // straight line equation: y-y1=m(x-x1) , gradient: m=y2-y1/x2-x1
    // X = (x1+ (dist *(x2-x1))) / (curr.distance(other)
    // Y = (y1+ (dist *(y2-y1))) / (curr.distance(other)
	return Point((curr._x + (dist * (other._x - curr._x) / curr.distance(other))), (curr._y + (dist * (other._y - curr._y) / curr.distance(other))));
    }

    string Point::print() const{
	return "(" + to_string(_x) + ", " + to_string(_y) + ")";
    }
}