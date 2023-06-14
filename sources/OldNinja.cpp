#include "OldNinja.hpp"

using namespace std;
using namespace ariel;

OldNinja::OldNinja(string name, const Point &location): Ninja(name, const_cast<Point&>(location), 150, 8) {}