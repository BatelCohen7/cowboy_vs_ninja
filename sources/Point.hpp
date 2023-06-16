#pragma once

#include <string>
#include <stdexcept>

using namespace std;

namespace ariel
{
	class Point
	{
		private:
			double _x;
			double _y;

		public:
			//default constructor.
			Point();

			//Construct a new Point object.
			Point(double _x, double _y);

            //geters
			double getX() const;
			double getY() const;

			//distance between this point and other point.
			double distance(Point other) const;

			// Returns the closest point to the other point, that is at most dist away from the origin point.
			static Point moveTowards(const Point &curr, const Point &other, double dist);

            //print point(x,y)
            std::string print() const;
	};
}