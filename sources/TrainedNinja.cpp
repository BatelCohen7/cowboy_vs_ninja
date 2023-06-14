#include "TrainedNinja.hpp"

using namespace std;
using namespace ariel;

TrainedNinja::TrainedNinja(string name, const Point &location): Ninja(name, const_cast<Point&>(location), 150, 8) {}